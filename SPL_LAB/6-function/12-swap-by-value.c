#include <stdio.h>

void swap(int a, int b) {
    int tmp = a;
    a       = b;
    b       = tmp;

    printf("func: %d %d\n", a, b);
}

int main(void) {
    int in1, in2;
    scanf("%d  %d", &in1, &in2);

    swap(in1, in2);

    printf("main: %d %d\n", in1, in2);

    return 0;
}
