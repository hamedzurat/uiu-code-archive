#include <stdio.h>

int main(void) {

    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = 1; j <= in - i + 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
