#include <stdio.h>

int main(void) {

    int in, fib = 1, old = 0;
    scanf("%d", &in);

    // printf("1, ");
    for(int i = 1; i <= in; i++) {
        printf("%d, ", fib);
        int tmp = fib;
        fib     = fib + old;
        old     = tmp;
    }

    return 0;
}
