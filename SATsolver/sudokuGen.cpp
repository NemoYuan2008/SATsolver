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
    int i, j, num;
    srand((int)time(0));
    sudokuClear();
    for (int k = 0; k < 40; k++) {
        i = randDigit();
        j = randDigit();
        num = randDigit() + 1;
        if (correct(i, j, num))
            sudoku[i][j] = -num;
    }
}
