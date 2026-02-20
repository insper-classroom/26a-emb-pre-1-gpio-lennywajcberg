#include "stdio.h"

void foo(int *a) {
    (*a)++;
}

int main(void) {
    int a = 0;
    int b = 0;

    while (a <= 5) {
        foo(&a);
    }
    b = 1;
    return b;
}