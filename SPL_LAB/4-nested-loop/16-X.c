#include <stdio.h>

int main(void) {
    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input / 2 + 2; i++) {
        for(int j = 0; j < i; j++)
            printf("-");

        printf("*");

        for(int j = 0; j < input - (2 * i); j++)
            printf("-");

        if(i != input / 2 + 1)
            printf("*");

        for(int j = 0; j < i; j++)
            printf("-");

        printf("\n");
    }

    for(int i = 0; i < input / 2 + 1; i++) {
        for(int j = 0; j < input / 2 - i; j++)
            printf("-");

        printf("*");

        for(int j = 0; j < (2 * i) + 1; j++)
            printf("-");

        printf("*");

        for(int j = 0; j < input / 2 - i; j++)
            printf("-");

        printf("\n");
    }

    return 0;
}
