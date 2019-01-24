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

void listCreate(void) {
    if ( !( head = (List)malloc(sizeof(Node)) ) ) {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }
}
