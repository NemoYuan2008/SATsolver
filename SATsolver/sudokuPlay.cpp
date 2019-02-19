//
//  sudokuPlay.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/2/19.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  数独游戏模块
//

#include <stdio.h>
#include <stdlib.h>
#include "SATsolver.h"

void play(void) {
    int line, row, num;
    while (!full()) {
        displaySudoku();
        printf("请输入行和列, 若选择的格子已经有填入的值, 将会删除这个值\n");
        printf("选择行[1-9], 输入0查看答案:");
        scanf("%d", &line);
        if (!line) {
            answer();
            return;
        }
        if (line > 9 || line < 1) {
            printf("输入不正确, 请重新输入!\n\n");
            continue;
        }
        
        printf("选择列[1-9]:");
        scanf("%d", &row);
        if (row > 9 || row < 1) {
            printf("输入不正确, 请重新输入!\n\n");
            continue;
        }
        
        if (sudoku[line-1][row-1] < 0) {
            printf("第%d行第%d列已经有数字了!\n\n", line, row);
            continue;
        }
        else if (sudoku[line-1][row-1] > 0) {
            printf("第%d行第%d列已经填了数字%d, 已删除\n\n", line, row,
                   sudoku[line-1][row-1]);
            sudoku[line-1][row-1] = 0;
            continue;
        }
        printf("输入数字[0-9]:");
        scanf("%d", &num);
        if (correct(line-1, row-1, num)) {
            sudoku[line-1][row-1] = num;
            printf("第%d行第%d列已填入数字%d\n\n", line, row, num);
        } else {
            printf("第%d行第%d列不能填入数字%d!\n\n", line, row, num);
        }
    }
    printf("恭喜你!已完成!\n");
}

bool correct(int a, int b, int x) {
    //检测行有无重复
    for (int i = 0; i < 9; i++) {
        if (i == b)
            continue;
        if (abs(sudoku[a][i]) == x)
            return false;
    }
    //检测列有无重复
    for (int i = 0; i < 9; i++) {
        if (i == a)
            continue;
        if (abs(sudoku[i][b]) == x)
            return false;
    }
    //检测九宫格有无重复
    int m = a/3, n = b/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m+i == a && n+j == b)
                continue;
            if (abs(sudoku[m+i][n+j]) == x)
                return false;
        }
    }
    return true;
}

bool full(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!sudoku[i][j])
                return false;
        }
    }
    return true;
}

void answer(void) {
    cnfOut();
    init();
    DPLL();
    sudokuFill();
    printf("答案为:\n");
    displaySudoku();
    clean();
}
