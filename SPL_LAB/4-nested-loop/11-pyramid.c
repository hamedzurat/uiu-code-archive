#include <stdio.h>

int main(void) {

    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = i; j < in; j++)
            printf("_");
        for(int j = 1; j < i * 2; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
