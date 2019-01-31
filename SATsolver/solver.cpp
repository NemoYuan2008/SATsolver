//
//  solver.cpp
//  SATsolver
//
//  Created by 袁博实 on 2019/1/25.
//  Copyright © 2019 袁博实. All rights reserved.
//
//  求解器核心模块
//

#include <stdio.h>
#include "SATsolver.h"

/*
 * 函数名称: DPLL
 * 接受参数: void
 * 函数功能: 运行DPLL算法以求解SAT问题, 解保存在*value中
 * 返回值: 若可满足返回true, 不可满足返回false
 */
bool DPLL(void) {
    int x = 0;
    bool backTrack = false;         //指示当前是否在回溯
    List backup;
    if (!simplifySingleClause())
        return false;
    if (satisfied())
        return true;
    
    while (1) {
        if (!backTrack)
            x = varDecide();
        listCopy(backup, head);     //将head备份起来
        push(backup, x);
        clauseInsert(x);        //令x为真, 进行化简
        if (!simplifySingleClause()) {  //化简后有空子句, 需要回溯
            listDestroy(head);
            head = pop();       //将head恢复为之前的状态
            if (!backTrack) {
                x = -x;
                backTrack = true;
            } else {
                listDestroy(head);
                if (stackEmpty())
                    return false;
                else {
                    x = -(top->x);
                    head = pop();
                }
            }
        } else {    //化简后没有空子句
            backTrack = false;
            if (satisfied())
                return true;
        }
    }//while
}//DPLL

/*
 * 函数名称: satisfied
 * 接受参数: void
 * 函数功能: 判断SAT是否已满足
 * 返回值: 若是返回true, 否则返回false
 */
bool satisfied(void) {
    return head->nextClause ? false : true;
}

/*
 * 函数名称: simplifySingleClause
 * 接受参数: void
 * 函数功能: 检查head中是否有单子句, 若有则利用规则化简
 * 返回值: 若化简后有空子句, 则返回false, 否则返回true
 */
bool simplifySingleClause(void) {
    int x;
    List prev, tail;
    tail = head;
    while (tail->nextClause) {
        prev = tail;
        tail = tail->nextClause;
        if (isSingleClause(tail)) {
            x = tail->nextLiteral->literal;
            if (x > 0)
                value[x-1] = true;
            else
                value[-x-1] = false;
            
            if(!simplify(x))    //化简后有空子句
                return false;
            tail = head;        //从头开始重新搜索单子句
        }
    }
    return true;
}

/*
 * 函数名称: simplify
 * 接受参数: 整数x, x为单子句变元
 * 函数功能: 利用x简化问题
 * 返回值: 若简化之后存在空子句, 返回false, 否则返回true
 */
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
                clauseTail = clausePrev;    //clauseTail被删除了, 要重新指向
                if (!(clauseTail->nextClause))
                    return true;                //已经遍历到了最后一个子句
                break;  //停止遍历这个子句的文字, 继续从下一个子句开始遍历
            }//if
            else if (literalTail->literal == -x) {
                literalDelete(literalPrev);     //从子句中删除这个文字
                literalTail = literalPrev;
                checkFlag = true;               //如果子句中删除了文字则需要检查该子句是否为空
            }//elif
            
            if (checkFlag && isEmptyClause(clauseTail))
                return false;
        }//while
    }//while
    return true;
}//simplify

/*
 * 函数名称: varDecide
 * 接受参数: void
 * 函数功能: 进行变元决策
 * 返回值: 决策出的变元, 若为真则为正数, 否则为负数
 */
int varDecide(void) {
    return head->nextClause->nextLiteral->literal;
}
