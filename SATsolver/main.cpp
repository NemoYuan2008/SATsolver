//
//  globalVar.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  主控函数main
//

#include <stdio.h>
#include <time.h>
#include "SATsolver.h"

int main(void) {
    int op = 1;     //用户输入
    bool solved;    //指示是否求解成功
    clock_t t1, t2;
    while (op) {
        displayMenu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                fileIn();
                listCreate();
                stackInit();
                t1 = clock();
                solved = DPLL();
                t2 = clock();
                timeCal(t1, t2);
                displayResult(solved);
                fileOut(solved);
                getchar();getchar();
                break;
            case 2:
                printf("数独部分待完成!\n");
                getchar();getchar();
                break;
            case 0:
                break;
            default:
                printf("输入错误, 请重试!\n");
                getchar();getchar();
                break;
        }
    }
    printf("再见!\n");
    return 0;
}
