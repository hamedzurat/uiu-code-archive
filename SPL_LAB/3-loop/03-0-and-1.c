#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        if(i % 2 == 0)
            printf("0, ");
        else
            printf("1, ");
    }

    return 0;
}
