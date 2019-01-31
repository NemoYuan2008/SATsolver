#include <stdio.h>
#include "SATsolver.h"

int main(void) {
    fileIn();
    listCreate();
    stackInit();
    if(!DPLL())
        return -1;
    for (int i = 0; i < boolCount; i++) {
        printf("%d", value[i]);
    }
    putchar('\n');
    return 0;
}
