#include <stdio.h>

int main() {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        if(i % 2 == 1)
            printf("(");
        else
            printf(")");
    }
    printf("\n");

    return 0;
}
