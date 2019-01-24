//
//  fileIO.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SATsolver.h"

/*
 * 函数名称: fileIn
 * 接受参数: void
 * 函数功能: 用文件指针fp打开用户指定的文件
 * 返回值: void
 */
void fileIn(void) {
    char fileName[50];
    printf("输入要读取的cnf文件:");
    scanf("%s", fileName);
    if ( !(fp = fopen(fileName, "r")) ) {
        fprintf(stderr, "文件打开失败!\n");
        exit(EXIT_FAILURE);
    }
    printf("文件打开成功!\n");
}

/*
 * 函数名称: init
 * 接受参数: void
 * 函数功能: 进行初始化，为cnf的存储做准备
 * 返回值: void
 */
void init(void) {
    char ch;
    while ( (ch = getc(fp)) == 'c') {
        while( (ch = getc(fp)) != '\n')
            continue;           //弃去一整行
    }   //运行到此，已经读取了字符p
    fscanf(fp, "%d", &boolCount);    //p后的第1个数值是布尔变元数量
    fscanf(fp, "%d", &clauseCount);  //p后的第2个数值是子句数量
}
