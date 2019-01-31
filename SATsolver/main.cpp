//
//  globalVar.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  主控函数main
//

#include <stdio.h>
#include "SATsolver.h"

int main(void) {
    fileIn();
    listCreate();
    stackInit();
    if(!DPLL())
        return -1;
    for (int i = 0; i < boolCount; i++) {
        printf("%d: %d\n", i + 1, value[i]);
    }
    putchar('\n');
    return 0;
}
