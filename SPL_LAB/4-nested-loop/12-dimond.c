#include <stdio.h>

int main(void) {

    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in / 2 + 1; i++) {
        for(int j = i; j < in / 2 + 1; j++)
            printf("_");
        for(int j = 1; j < i * 2; j++)
            printf("*");
        printf("\n");
    }
    for(int i = in / 2; i > 0; i--) {
        for(int j = 0; j <= (in / 2) - i; j++)
            printf("_");
        for(int j = 1; j < i * 2; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
