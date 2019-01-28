#include <stdio.h>
#include "SATsolver.h"

int main(void) {
    fileIn();
    listCreate();
    stackInit();
    DPLL();
    for (int i = 0; i < boolCount; i++) {
        printf("%d", value[i]);
    }
    putchar('\n');
    return 0;
}
