#include <stdio.h>

int main(void) {
    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        for(int j = 0; j < input - 1 - i; j++)
            printf("   ");

        for(int j = 1; j <= i + 1; j++)
            printf(" %2d", (i + j) * 2);

        for(int j = i; j >= 1; j--)
            printf(" %2d", (i + j) * 2);

        printf("\n");
    }

    return 0;
}
