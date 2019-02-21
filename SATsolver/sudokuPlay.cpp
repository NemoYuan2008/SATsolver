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

/*
 * 函数名称: play
 * 接受参数: void
 * 函数功能: 玩数独
 * 返回值: void
 */
void play(void) {
    int line, row, num;
    while (!isFull()) {
        system("clear");
        displaySudoku();
        printf("请输入行和列, 若选择的格子已经有填入的值, 将会删除这个值\n");
        printf("选择行[1-9], 输入0查看答案:");
        scanf("%d", &line);
        if (!line) {
            answer();
            printf("你输了!答案为:\n");
            displaySudoku();
            return;
        }
        if (line > 9 || line < 1) {
            printf("输入不正确, 请重新输入!\n\n");
            printf("按[enter]键继续...");
            continue;
        }
        
        printf("选择列[1-9]:");
        scanf("%d", &row);
        if (row > 9 || row < 1) {
            printf("输入不正确, 请重新输入!\n\n");
            printf("按[enter]键继续...");
            getchar(); getchar();
            continue;
        }
        
        if (sudoku[line-1][row-1] < 0) {
            printf("第%d行第%d列已经有数字了!\n\n", line, row);
            printf("按[enter]键继续...");
            getchar(); getchar();
            continue;
        }
        else if (sudoku[line-1][row-1] > 0) {
            printf("第%d行第%d列已经填了数字%d, 已删除\n\n", line, row,
                   sudoku[line-1][row-1]);
            sudoku[line-1][row-1] = 0;
            printf("按[enter]键继续...");
            getchar(); getchar();
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
        printf("按[enter]键继续...");
        getchar(); getchar();
    }
    printf("恭喜你!已完成!\n");
}

/*
 * 函数名称: correct
 * 接受参数: 行数a, 列数b, 1-9的整数x
 * 函数功能: 判断sudoku[a][b]是否可以为x
 * 返回值: 若可以返回true, 否则返回false
 */
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
            if (3*m + i == a && 3*n + j == b)
                continue;
            if (abs(sudoku[3*m+i][3*n+j]) == x)
                return false;
        }
    }
    return true;
}

/*
 * 函数名称: isFull
 * 接受参数: void
 * 函数功能: 判断数独是否已经填满
 * 返回值: 若是返回true, 否则返回false
 */
bool isFull(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!sudoku[i][j])
                return false;
        }
    }
    return true;
}
