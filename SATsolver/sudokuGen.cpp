//
//  sudokuGen.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/2/20.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  数独生成模块
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SATsolver.h"

/*
 * 函数名称: randDigit
 * 接受参数: void
 * 函数功能: 返回一个0-9的随机整数
 * 返回值: 一个0-9的随机整数
 */
int randDigit(void) {
    return rand() % 9;
}

/*
 * 函数名称: sudokuGenerate
 * 接受参数: void
 * 函数功能: 生成数独
 * 返回值: void
 */
void sudokuGenerate(void) {
    srand((int)time(0));
    sudokuClear();
    //随机填12个数
    for (int k = 0; k < 12; ) {
        int i = randDigit();
        int j = randDigit();
        int num = randDigit() + 1;
        if (correct(i, j, num)) {
            sudoku[i][j] = -num;
            k++;
        }
    }
    answer(1);      //利用随机的12个数字生成终盘
    //随机挖掉45个空
    for (int k = 0; k < 45; ) {
        int i = randDigit();
        int j = randDigit();
        if (sudoku[i][j]) {
            sudoku[i][j] = 0;
            k++;
        }
    }
    //answer()会把sudoku里面的数全部变成正, 要重新变成负数
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = -sudoku[i][j];
        }
    }
}
