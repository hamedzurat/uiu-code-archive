#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);

    // series starts from 10
    // difference of the series starts from 5
    int r1 = 5, r0 = 10, sum = 0;
    for(int i = 1; i <= input; i++) {
        // printf("%d ", r1);
        printf("%d ", r0);

        // adding all up
        sum = sum + r0;

        // generating the next number using the difference series
        r0 = r0 + r1;

        // generating the difference series
        // second layer difference is always 8
        r1 = r1 + 8;
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
