#include <stdio.h>

int main(void) {
    int in, i, j;

    scanf("%d", &in);

    for(i = 1; i <= in; i++) {
        for(j = 1; j <= (in - i); j++)
            printf(" ");

        for(j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}
