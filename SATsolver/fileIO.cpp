//
//  fileIO.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  文件输入输出模块
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SATsolver.h"

/*
 * 函数名称: fileIn
 * 接受参数: void
 * 函数功能: 用文件指针fp打开用户指定的文件
 * 返回值: void
 */
void fileIn(void) {
    printf("输入要读取的cnf文件:");
    scanf("%s", fileName);
    if ( !(fp = fopen(fileName, "r")) ) {
        fprintf(stderr, "文件打开失败!\n");
        exit(EXIT_FAILURE);
    }
    printf("文件打开成功!\n正在求解...\n");
}

/*
 * 函数名称: init
 * 接受参数: void
 * 函数功能: 进行初始化, 弃去文件中没有用的字符, 为cnf的存储做准备
 * 返回值: void
 */
void init(void) {
    char ch;
    while ( (ch = getc(fp)) == 'c') {
        while( (ch = getc(fp)) != '\n')
            continue;           //弃去一整行
    }   //运行到此，已经读取了字符p
    getc(fp); getc(fp); getc(fp); getc(fp); //弃去cnf三个字母
    fscanf(fp, "%d", &boolCount);    //p后的第1个数值是布尔变元数量
    fscanf(fp, "%d", &clauseCount);  //p后的第2个数值是子句数量
    
    value = (bool *)calloc(boolCount, sizeof(bool));    //为value分配空间
}

/*
 * 函数名称: fileOut
 * 接受参数: 指示是否有解的布尔值solved
 * 函数功能: 将求解结果写入文件中
 * 返回值: void
 */
void fileOut(bool solved) {
    strcat(fileName, ".res");   //输出保存在后缀.res的同名文件中
    fp = fopen(fileName, "w");
    if (!fp) {
        fprintf(stderr, "文件写入失败!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "s ");
    if (solved) {
        fprintf(fp, "1\n");
        for (int i = 1; i < boolCount; i++) {
            fprintf(fp, "%d ", value[i] ? i : -i);
        }//for
    } else {
        fprintf(fp, "0");
    }//else
    fprintf(fp, "\nt %d\n", timeConsumed);
    fclose(fp);
    printf("结果已经成功写入到文件%s中\n", fileName);
}
