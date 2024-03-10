#include <math.h>
#include <stdio.h>

int main(void) {
    int x = 0;
    scanf("%d", &x);
    // printf("input: %d\t", x);
    double v = log2(x);

    if(x == 0)
        printf("zero is not valid\n");
    else if(x < 0)
        printf("negative is not valid input\n");
    else if(ceil(v) == v)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
