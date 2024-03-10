#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    if(x > y)
        printf("%d is greatrer than %d", x, y);
    else if(x < y)
        printf("%d is less than %d", x, y);
    else
        printf("%d is equal to %d", x, y);

    return 0;
}
