#include <stdio.h>

int main(void) {

    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = 1, k = i; j <= in; j++, k++)
            printf("%d", (k % 2));
        printf("\n");
    }
    return 0;
}
