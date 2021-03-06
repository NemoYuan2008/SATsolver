//
//  SATsolver.h
//  SATsolver
//
//  Created by 袁博实 on 2019/1/24.
//  Copyright © 2019 袁博实. All rights reserved.
//

#ifndef SATsolver_h
#define SATsolver_h

#include <stdio.h>      //提供FILE *类型
#include <time.h>       //提供clock_t类型

/*
 * 函数名称:
 * 接受参数:
 * 函数功能:
 * 返回值:
 */

/* 存储结构声明 */
typedef struct LNode {
    union {
        int literal;
        struct LNode * nextClause;   //指向下一个子句
    };
    struct LNode * nextLiteral;      //指向下一个文字
} LNode, *List;

typedef struct Snode {
    int x;
    bool backTrack;
    List data;
    struct Snode * next;
} Snode, * Stack;   //链式堆栈

/* 全局变量引用声明 */
extern List head;
extern Stack top;
extern FILE * fp;
extern char fileName[200];
extern int clauseCount;
extern int boolCount;
extern bool * value;
extern unsigned timeUsed;
extern int sudoku[9][9];

/* 函数原型 */
void fileOpen(bool write);                              //fileIO.cpp
void init(bool sudoku);                                //fileIO.cpp
void fileOut(bool solved);                      //fileIO.cpp
void sudokuIn(void);
void listCreate(void);                          //listOperate.cpp
void listCopy(List & dest, const List src);     //listOperate.cpp
void listDestroy(List & delHead);               //listOperate.cpp
void clauseInsert(int x);                       //listOperate.cpp
void clauseDelete(List & prev);                 //listOperate.cpp
void literalDelete(List & prev);                //listOperate.cpp
bool isEmptyClause(List clause);                //listOperate.cpp
bool isSingleClause(List clause);               //listOperate.cpp
bool DPLL(void);                                //solver.cpp
bool satisfied(void);                           //solver.cpp
bool simplifySingleClause(void);                //solver.cpp
bool simplify(int x);                           //solver.cpp
int varDecide(void);                            //solver.cpp
void stackInit(void);                           //stack.cpp
bool stackEmpty(void);                          //stack.cpp
void push(List backup, int x, bool backTrack);  //stack.cpp
List pop(void);                                 //stack.cpp
void clean(void);                        //stack.cpp
void displayMenu(void);                         //display.cpp
void cnfVerify(void);
void displayResult(bool solved);                //display.cpp
void printList(List printHead);
void displaySudoku(void);
void timeCal(clock_t t1, clock_t t2);           //timeCal.cpp
void cnfOut(bool generate);
void sudokuFill(void);
void answer(bool generate);
void sudokuClear(void);
void play(void);
bool correct(int a, int b, int x);
bool isFull(void);
int randDigit(void);
void sudokuGenerate(void);

#endif /* SATsolver_h */
