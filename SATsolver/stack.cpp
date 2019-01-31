//
//  stack.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/26.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  堆栈操作模块
//

#include <stdio.h>
#include <stdlib.h>
#include "SATsolver.h"

/*
 * 函数名称: stackInit
 * 接受参数: void
 * 函数功能: 初始化链式堆栈top
 * 返回值: void
 */
void stackInit(void) {
    top = (Stack)malloc(sizeof(Snode));
    top->next = NULL;
    top->data = NULL;
}

/*
 * 函数名称: stackEmpty
 * 接受参数: void
 * 函数功能: 判断链式堆栈top是否为空
 * 返回值: 若为空返回true, 否则返回false
 */
bool stackEmpty(void) {
    return top->next ? false : true;
}

/*
 * 函数名称: push
 * 接受参数: 邻接表头指针backup, 整数x
 * 函数功能: 将backup和x入栈
 * 返回值: void
 */
void push(List backup, int x) {
    Stack ins = (Stack)malloc(sizeof(Snode));
    ins->data = backup;
    ins->x = x;
    ins->next = top;
    top = ins;
}

/*
 * 函数名称: pop
 * 接受参数: void
 * 函数功能: 从堆栈中弹出一个元素
 * 返回值: 弹出的邻接表头指针
 */
List pop(void) {
    List ret_val = top->data;
    Stack del = top;
    top = top->next;
    free(del);
    del = NULL;
    return ret_val;
}

/*
 * 函数名称: stackDestroy
 * 接受参数: void
 * 函数功能: 销毁链式堆栈top
 * 返回值: void
 */
void stackDestroy(void) {
    Stack del;
    while (top->next) {
        del = top;
        top = top->next;
        free(del);
    }
    free(top);
    top = NULL;
}
