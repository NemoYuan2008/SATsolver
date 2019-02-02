//
//  test.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/28.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  测试程序使用的代码
//  正式发布时删除这个文件
//

#include <stdio.h>
#include "SATsolver.h"

#ifdef testing

void printList(List printHead) {
    List clauseTail, literalTail;
    clauseTail = printHead;
    while (clauseTail->nextClause) {
        clauseTail = clauseTail->nextClause;
        literalTail = clauseTail;
        while (literalTail->nextLiteral) {
            literalTail = literalTail->nextLiteral;
            printf("%d ", literalTail->literal);
        }
        putchar('\n');
    }
    printf("\n");
}

#endif
