#include <math.h>
#include <stdio.h>

/**
not valid bc said algo is not what i wrote
**/
int main(void) {
    int x = 0;
    scanf("%d", &x);
    printf("input: %d\t", x);

    if(x == 0) {
        printf("zero is not valid\n");
    } else if(x < 0) {
        printf("neg is not valid input\n");
    } else if(x & (x - 1)) {
        // printf("no\n");
        printf(".\n");
    } else {
        printf("yes\n");
    }

    return 0;
}
