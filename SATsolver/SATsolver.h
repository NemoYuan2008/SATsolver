#ifndef SATsolver_h
#define SATsolver_h

/* 存储结构声明 */
typedef struct Node {
    union {
        int literal;
        struct Node * nextClause;   //指向下一个字句
    };
    struct Node * nextLiteral;     //指向下一个文字
} Node, *List;

/* 全局变量引用声明 */
extern List head;
extern FILE * fp;
extern int clauseCount;

/* 函数原型 */
void fileOpen(void);          //fileIO.cpp

#endif /* SATsolver_h */
