#include <stdio.h>

int main(void) {

    int i;
    scanf("%d", &i);
    while(i != 0) {
        printf("%d", (i % 10));
        i = i / 10;
    }

    return 0;
}
