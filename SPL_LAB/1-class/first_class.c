#include <stdio.h>

int main(void) {
    // 1
    printf("Hello World\n\n");

    // 2
    printf("Hello World\nThis is my first program.\tC is fun.\n\n");

    // 3
    printf("The question is - \"Hello World\\commentr/ is C programming language?\"\n\n");

    // 4
    int i   = 5;
    float f = 3.1416;
    char c  = 'a';

    printf("The integer value: %d\nThe floatng point value: %f\nThe character value: %c\n\n", i, f, c);

    // 5
    int j;
    int g = 1111;
    int q = 1, w = 2;
    int o, k, p;
    k = p = o = 99;

    // 6
    int age;
    scanf("%d", &age);
    printf("My age is %d\n", age);

    // 7
    int in_i;
    float in_f;
    char in_c;

    scanf("%d %f %c", &in_i, &in_f, &in_c);
    printf("The integer value: %d\n", in_i);
    printf("The floating point value: %f\n", in_f);
    printf("The character value: %c\n", in_c);

    return 0;
}
