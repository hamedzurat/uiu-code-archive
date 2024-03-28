#include <stdio.h>

int factorial(int A) {
    return (A == 1) ? 1 : A * factorial(--A);
}

int main(void) {
    int input;
    scanf("%d", &input);

    printf("%d", factorial(input));

    return 0;
}
