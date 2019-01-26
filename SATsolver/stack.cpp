//
//  stack.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/26.
//  Copyright © 2019 袁博实. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SATsolver.h"

void stackInit(void) {
    top = (Stack)malloc(sizeof(Snode));
    top->next = NULL;
}

bool stackEmpty(void) {
    return top->next ? false : true;
}

void push(List x) {
    Stack ins = (Stack)malloc(sizeof(Snode));
    ins->data = x;
    ins->next = top;
    top->next = ins;
}

List pop(void) {
    List ret_val = top->data;
    Stack del = top;
    top = top->next;
    free(del);
    del = NULL;
    return ret_val;
}

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
