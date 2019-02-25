//
//  sudokuSolve.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/2/8.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  数独求解模块
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SATsolver.h"

#define boolGen(a, b, c) (100*(a) + 10*(b) + (c))

/*
 * 函数名称: cnfOut
 * 接受参数: generate, 指示当前是否在生成数独
 * 函数功能: 将数独转化为cnf并输出到文件中
 * 返回值: void
 */
void cnfOut(bool generate) {
    clauseCount = 0;
    if (generate) {
        strcpy(fileName, "generate.cnf");
    } else {
        printf("输入要保存数独对应的cnf的路径:");
        scanf("%s", fileName);
    }
    fileOpen(1);
    //占位
    fprintf(fp, "c cnf generated from sudoku\n");
    fprintf(fp, "p cnf 889       ");
    //已知条件作为单子句
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (sudoku[x][y] < 0) {
                fprintf(fp, "%d 0\n", 100*x + 10*y - sudoku[x][y]);
                clauseCount++;
            }
        }
    }
    //每格最少一个数字
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            for (int z = 1; z <= 9; z++) {
                fprintf(fp, "%d ", boolGen(x, y, z));
            }
            fprintf(fp, "0\n");
            clauseCount++;
        }
    }
    //每格最多一个数字
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            for (int z = 1; z <= 8; z++) {
                for (int i = z + 1; i < 9; i++) {
                    fprintf(fp, "%d %d 0\n", -boolGen(x, y, z),
                            -boolGen(x, y, i));
                    clauseCount++;
                }
            }
        }
    }
    //每行不重复
    for (int y = 0; y < 9; y++) {
        for (int z = 1; z <= 9; z++) {
            for (int x = 0; x < 8; x++) {
                for (int i = x + 1; i < 9; i++) {
                    fprintf(fp, "%d %d 0\n", -boolGen(x, y, z),
                            -boolGen(i, y, z));
                    clauseCount++;
                }
            }
        }
    }
    //每列不重复
    for (int x = 0; x < 9; x++) {
        for (int z = 1; z <= 9; z++) {
            for (int y = 0; y < 9; y++) {
                for (int i = y + 1; i < 9; i++) {
                    fprintf(fp, "%d %d 0\n", -boolGen(x, y, z),
                            -boolGen(x, i, z));
                    clauseCount++;
                }
            }
        }
    }
    //每个九宫格不重复
    for (int z = 1; z <= 9; z++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        for (int k = y + 1; k < 3; k++) {
                            fprintf(fp, "%d %d 0\n", -boolGen(3*i + x, 3*j + y, z),
                                    -boolGen(3*i + x, 3*j + k, z));
                            clauseCount++;
                        }
                    }
                }
            }
        }
    }
    for (int z = 1; z <= 9; z++) {
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        for (int k = x + 1; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                fprintf(fp, "%d %d 0\n", -boolGen(3*i + x, 3*j + y, z),
                                        -boolGen(3*i + k, 3*j + l, z));
                                clauseCount++;
                            }
                        }
                    }
                }
            }
        }
    }
    rewind(fp);
    fprintf(fp, "c cnf generated from sudoku\n");
    fprintf(fp, "p cnf 889 %d\n", clauseCount);
    fclose(fp);
    if (!generate)
        printf("cnf已生成!已保存在%s\n", fileName);
}

/*
 * 函数名称: sudokuFill
 * 接受参数: void
 * 函数功能: 利用已经解出的SAT问题填充数独
 * 返回值: void
 */
void sudokuFill(void) {
    for (int i = 1; i <= 899; i++) {
        if (i % 10 == 0)
            continue;
        if (value[i-1])
            sudoku[i/100][(i/10)%10] = i%10;
    }
}

/*
 * 函数名称: answer
 * 接受参数: generate, 指示当前是否在生成数独
 * 函数功能: 求出数独的答案, 保存在sudoku中
 * 返回值: void
 */
void answer(bool generate) {
    cnfOut(generate);
    init(1);
    DPLL();
    sudokuFill();
    clean();
}

/*
 * 函数名称: sudokuClear
 * 接受参数: void
 * 函数功能: 将数独清空
 * 返回值: void
 */
void sudokuClear(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = 0;
        }
    }
}
