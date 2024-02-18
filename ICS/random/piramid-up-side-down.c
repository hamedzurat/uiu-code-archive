#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = 1; j < i; j++) {
            printf("_");
        }
        for(int j = 0; j <= (in - i); j++) {
            printf("*_");
        }
        printf("\n");
    }

    return 0;
}
