#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    if(x < y) {
        for(int i = x; i < y; i++)
            printf("%d, ", i * i);

    } else if(x > y) {
        for(int i = x; i > y; i--)
            printf("%d, ", i * i);
    }

    printf("reached!");

    return 0;
}
