#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = i; j < in; j++)
            printf(" ");

        if(i == in)
            for(int j = 0; j < in; j++)
                printf("* ");
        else
            for(int j = 0; j < i; j++) {
                if(j == 0 || j == (i - 1))
                    printf("* ");
                else
                    printf("  ");
            }

        printf("\n");
    }

    return 0;
}
