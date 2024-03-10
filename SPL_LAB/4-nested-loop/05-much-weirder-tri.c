#include <stdio.h>

int main(void) {

    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        for(int j = 1, k = in; j <= i; j++, k--)
            printf("%d", k);
        printf("\n");
    }
    return 0;
}
