#include <math.h>
#include <stdio.h>

int main(void) {
    int input, digit = 0;
    scanf("%d", &input);

    int i = input, n = input, j = 0;

    while(n != 0) {
        n = n / 10;
        ++digit;
    }

    while(i != 0) {
        j = j + pow((i % 10), digit);
        i = i / 10;

        // printf("%d %d\n", i, j);
    }

    if(input == j)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    return 0;
}
