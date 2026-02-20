#include <stdio.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a = 5;
    int b = 5;
    int result = multiplyNumbers(a, b);

    int arr[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i;
    }

    printf("result=%d, arr[0]=%d, arr[%d]=%d\n",
           result, arr[0], NUM_ELEMENTS - 1, arr[NUM_ELEMENTS - 1]);

    return 0;
}