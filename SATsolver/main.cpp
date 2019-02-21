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
#include <stdlib.h>
#include <time.h>
#include "SATsolver.h"

int main(void) {
    int op = 1;     //用户输入
    bool solved;    //指示是否求解成功
    clock_t t1, t2;
    while (op) {
        system("clear");
        displayMenu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                init(0);
                cnfVerify();
                printf("正在求解...\n");
                t1 = clock();
                solved = DPLL();
                t2 = clock();
                clean();
                timeCal(t1, t2);
                displayResult(solved);
                fileOut(solved);
                printf("按[enter]键继续...");
                getchar();getchar();
                break;
            case 2:
                sudokuIn();
                play();
                printf("按[enter]键继续...");
                getchar();getchar();
                break;
            case 3:
                sudokuGenerate();
                play();
                printf("按[enter]键继续...");
                getchar();getchar();
                break;
            case 0:
                break;
            default:
                printf("输入错误, 按[enter]键继续...");
                getchar();getchar();
                break;
        }
    }
    printf("再见!\n");
    return 0;
}
