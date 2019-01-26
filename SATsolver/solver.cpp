//
//  solver.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/25.
//  Copyright © 2019 袁博实. All rights reserved.
//

#include <stdio.h>
#include "SATsolver.h"

bool DPLL(void) {
    int x;
    List prev, tail;
    tail = head;
    while (tail->nextClause) {  //单子句传播
        prev = tail;
        tail = tail->nextClause;
        
        if (isSingleClause(tail)) {
            x = tail->nextLiteral->literal;
            if (x > 0)
                value[x-1] = true;
            else
                value[-x-1] = false;
            
            if (!simplify(x))   //化简后有空子句
                return false;
            if (!clauseCount)   //子句已经全部被满足
                return true;
        }//if
    }//while
}//DPLL

bool simplify(int x) {
    bool checkFlag;     //指示是否需要检查空子句
    List clauseTail, clausePrev, literalTail, literalPrev;
    clauseTail = head;
    
    //遍历所有的子句
    while (clauseTail->nextClause) {
        checkFlag = false;
        clausePrev = clauseTail;
        clauseTail = clauseTail->nextClause;
        
        //遍历子句中的文字
        literalTail = clauseTail;
        while (literalTail->nextLiteral) {
            literalPrev = literalTail;
            literalTail = literalTail->nextLiteral;
            
            if (literalTail->literal == x) {
                clauseDelete(clausePrev);       //删除这个子句
                clauseTail = clausePrev->nextClause;    //clauseTail被删除了, 要指向下一个子句
                if (!clauseTail)
                    return true;                //已经遍历到了最后一个子句
                break;  //停止遍历这个子句到文字, 继续从下一个子句开始遍历
            }//if
            else if (literalTail->literal == -x) {
                literalDelete(literalPrev);     //从子句中删除这个文字
                checkFlag = true;               //如果子句中删除了文字则需要检查该子句是否为空
            }//elif
            
            if (checkFlag && isEmptyClause(clauseTail))
                return false;
        }//while
    }//while
    return true;
}//simplify


