//
//  display.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/31.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  显示模块
//

#include <stdio.h>
#include "SATsolver.h"

/*
 * 函数名称: displayMenu
 * 接受参数: void
 * 函数功能: 显示主菜单
 * 返回值: void
 */
void displayMenu(void) {
    printf("----主菜单----\n");
    printf("1: 求解SAT问题\n");
    printf("2: 数独\n");
    printf("0: 退出\n");
    printf("\n请选择:");
}

/*
 * 函数名称: displayResult
 * 接受参数: 指示是否有解的布尔值solved
 * 函数功能: 显示求解结果
 * 返回值: void
 */
void displayResult(bool solved) {
    if (solved) {
        printf("求解成功!结果如下:\n");
        for (int i = 1; i <= boolCount; i++)
            printf("%d ", value[i-1] ? i : -i);
        putchar('\n');
    } else {
        printf("该SAT不可满足!\n");
    }
    printf("DPLL过程用时:%u ms\n", timeUsed);
}
