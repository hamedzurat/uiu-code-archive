#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int j = 0; j < in; j++)
        printf("* ");
    printf("\n");

    for(int i = 1; i < in; i++) {
        for(int j = 0; j < i; j++)
            printf(" ");

        for(int j = i; j < in; j++) {
            if(j == i || j == (in - 1))
                printf("* ");
            else
                printf("  ");
        }

        printf("\n");
    }

    return 0;
}
