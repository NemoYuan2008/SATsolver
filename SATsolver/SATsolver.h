#ifndef SATsolver_h
#define SATsolver_h

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
    List data;
    struct Snode * next;
} Snode, * Stack;   //链式堆栈

/* 全局变量引用声明 */
extern List head;
extern Stack top;
extern FILE * fp;
extern int clauseCount;
extern int boolCount;
extern bool * value;

/* 函数原型 */
void fileIn(void);                              //fileIO.cpp
void init(void);                                //fileIO.cpp
void listCreate(void);                          //listOperate.cpp
void listCopy(List & dest, const List src);     //listOperate.cpp
void listDestroy(List & delHead);
void clauseInsert(int x);
void clauseDelete(List & prev);                 //listOperate.cpp
void literalDelete(List & prev);                //listOperate.cpp
bool isEmptyClause(List clause);                //listOperate.cpp
bool isSingleClause(List clause);               //listOperate.cpp
bool DPLL(void);                                //solver.cpp
bool satisfied(void);
bool simplifySingleClause(void);
bool simplify(int x);                           //solver.cpp
int varDecide(void);
void stackInit(void);
bool stackEmpty(void);
void push(List backup, int x);
List pop(void);
void stackDestroy(void);

#endif /* SATsolver_h */
