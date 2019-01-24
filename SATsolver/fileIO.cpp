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
 * 函数名称: fileOpen
 * 接受参数: void
 * 函数功能: 用文件指针fp打开用户指定的文件
 * 返回值: void
 */
void fileOpen(void) {
    char fileName[50];
    printf("输入要读取的cnf文件:");
    scanf("%s", fileName);
    if ( !(fp = fopen(fileName, "r")) ) {
        fprintf(stderr, "文件读取失败!\n");
        exit(EXIT_FAILURE);
    }
    printf("文件读取成功!\n");
}

void fileIn(void) {
    fileOpen();
    
}
