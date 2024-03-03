#include <stdio.h>

int main(void) {
    int in, sum = 0;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        sum = sum + (i * i * (i + 1));
    }
    printf("%d", sum);

    return 0;
}
