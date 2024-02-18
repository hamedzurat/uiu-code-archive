#include <stdio.h>

int main() {
    int i;
    scanf("%d", &i);

    while(i != 0) {
        printf("%d", (i % 10));
        i = i / 10;
    }

    printf("\n");

    return 0;
}
