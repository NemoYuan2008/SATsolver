#ifndef SATsolver_h
#define SATsolver_h

/* 存储结构声明 */
typedef struct LNode {
    union {
        int literal;
        struct LNode * nextClause;   //指向下一个子句
    };
    struct LNode * nextLiteral;      //指向下一个文字
} LNode, *List;

/* 全局变量引用声明 */
extern List head;
extern FILE * fp;
extern int clauseCount;
extern int boolCount;
extern bool * value;

/* 函数原型 */
void fileIn(void);                  //fileIO.cpp
void init(void);                    //fileIO.cpp
void listCreate(void);              //listOperate.cpp
void clauseDelete(List & prev);     //listOperate.cpp
void literalDelete(List & prev);    //listOperate.cpp
void clauseInsert(List ins);        //listOperate.cpp
bool isEmptyClause(List clause);    //listOperate.cpp
bool isSingleClause(List clause);   //listOperate.cpp
bool DPLL(void);                    //solver.cpp
bool simplify(int x);               //solver.cpp

#endif /* SATsolver_h */
