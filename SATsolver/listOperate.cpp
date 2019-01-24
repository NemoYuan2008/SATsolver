//
//  listOperate.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SATsolver.h"

/*
 * 函数名称: listCreate
 * 接受参数: void
 * 函数功能: 从文件fp中读取数据并创建十字链表
 * 返回值: void
 */
void listCreate(void) {
    List clauseTail, literalTail;   //尾指针
    int literal;                    //临时存放从文件中输入的子句的值
    init();                         //先进行初始化
    if ( !( head = (List)malloc(sizeof(Node)) ) ) {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }
    head->nextClause = NULL;
    head->nextLiteral = NULL;
    clauseTail = head;
    
    //创建数量为clauseCount的子句, i为计数器
    for (int i = 0; i < clauseCount; i++) {
        clauseTail->nextClause = (List)malloc(sizeof(Node));
        clauseTail = clauseTail->nextClause;
        clauseTail->nextClause = NULL;
        
        //准备每一个子句创建文字链表
        literalTail = clauseTail;
        fscanf(fp, "%d", &literal);
        while (literal != 0) {
            literalTail->nextLiteral = (List)malloc(sizeof(Node));
            literalTail = literalTail->nextLiteral;
            literalTail->nextLiteral = NULL;
            literalTail->literal = literal;     //将输入值拷贝到节点
            fscanf(fp, "%d", &literal);
        }
    }
}
