#ifndef SATsolver_h
#define SATsolver_h

/* 存储结构声明 */
typedef struct Node {
    union {
        int literal;
        struct Node * nextClause;   //指向下一个子句
    };
    struct Node * nextLiteral;      //指向下一个文字
} Node, *List;

/* 全局变量引用声明 */
extern List head;
extern FILE * fp;
extern int clauseCount;
extern int boolCount;

/* 函数原型 */
void fileIn(void);          //fileIO.cpp
void init(void);            //fileIO.cpp
void listCreate(void);      //listOperate.cpp

#endif /* SATsolver_h */
