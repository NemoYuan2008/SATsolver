//
//  globalVar.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  声明全局变量

#include <stdio.h>
#include "SATsolver.h"

List head;          //头节点指针
List headBackup;    //存放备份
Stack top;          //链式堆栈栈顶指针
FILE * fp;          //文件指针
int clauseCount;    //当前子句数量
int boolCount;      //布尔变元数量
bool * value;       //存放布尔变元的值, 在init()中被分配空间
