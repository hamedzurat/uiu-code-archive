#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    for(int i = 1, j = 1; j <= input; i = i + 2, j++) {
        printf("%d\t", i);
    }

    return 0;
}
