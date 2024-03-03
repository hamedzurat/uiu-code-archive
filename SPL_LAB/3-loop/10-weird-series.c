#include <stdio.h>

int main(void) {
    int in, sum = 0;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        if(i % 2 == 0)
            sum = sum + (i * -1);
        else
            sum = sum + i;
    }
    printf("%d", sum);

    return 0;
}
