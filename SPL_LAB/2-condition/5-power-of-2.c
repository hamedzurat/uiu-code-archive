#include <math.h>
#include <stdio.h>

int main(void) {
    double num = 0;
    scanf("%lf", &num);
    // printf("input: %lf\t", num);

    double v = log2(num);

    if(ceil(v) == v)
        printf("yes");
    else
        printf("no");

    return 0;
}
