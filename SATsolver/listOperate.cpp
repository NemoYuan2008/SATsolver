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
    if ( !( head = (List)malloc(sizeof(LNode)) ) ) {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }
    head->nextClause = NULL;
    head->nextLiteral = NULL;
    clauseTail = head;
    
    //创建数量为clauseCount的子句, i为计数器
    for (int i = 0; i < clauseCount; i++) {
        clauseTail->nextClause = (List)malloc(sizeof(LNode));
        clauseTail = clauseTail->nextClause;
        clauseTail->nextClause = NULL;
        
        //准备每一个子句创建文字链表
        literalTail = clauseTail;
        fscanf(fp, "%d", &literal);
        while (literal != 0) {
            literalTail->nextLiteral = (List)malloc(sizeof(LNode));
            literalTail = literalTail->nextLiteral;
            literalTail->nextLiteral = NULL;
            literalTail->literal = literal;     //将输入值拷贝到节点
            fscanf(fp, "%d", &literal);
        }
    }
}

/*
 * 函数名称: clauseDelete
 * 接受参数: 指向待删除节点的前一个节点的指针
 * 函数功能: 删除一个子句节点
 * 返回值: void
 */
void clauseDelete(List & prev) {
    List del = prev->nextClause;    //待删除的节点
    prev->nextClause = del->nextClause;
    free(del);
    del = NULL;
    clauseCount--;      //当前子句数量减1
}

/*
 * 函数名称: literalDelete
 * 接受参数: 指向待删除节点的前一个节点的指针
 * 函数功能: 删除子句中的一个文字节点
 * 返回值: void
 */
void literalDelete(List & prev) {
    List del = prev->nextLiteral;   //待删除的节点
    prev->nextLiteral = del->nextLiteral;
    free(del);
    del = NULL;
}

/*
 * 函数名称: clauseInsert
 * 接受参数: 指向子句节点的指针
 * 函数功能: 将该子句节点插入到head的后面
 * 返回值: void
 */
void clauseInsert(List ins) {
    ins->nextClause = head->nextClause;
    head->nextClause = ins;
}

/*
 * 函数名称: isEmptyClause
 * 接受参数: 指向子句节点的指针
 * 函数功能: 判断子句是否是空子句
 * 返回值: 若是空子句返回true, 否则返回false
 */
bool isEmptyClause(List clause) {
    return clause->nextLiteral ? false : true;
}

/*
 * 函数名称: isSingleClause
 * 接受参数: 指向非空子句节点的指针
 * 函数功能: 判断非空子句是否是单子句
 * 返回值: 若是单子句返回true, 否则返回false
 */
bool isSingleClause(List clause) {
    return clause->nextLiteral->nextLiteral ? false : true;
}
