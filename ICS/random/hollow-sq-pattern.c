#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    // in picture there is 6 row and 5 columm
    // i will take it as input for 5
    // changing value of i = 1 will make it a squire

    for(int i = 0; i <= in; i++) {
        if(i == 0 || i == in) {
            for(int j = 0; j < in; j++)
                printf("* ");
        } else {
            for(int j = 0; j < in; j++) {
                if(j == 0 || j == in - 1)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
