#include <math.h>
#include <stdio.h>

int main(void) {
    // double num = 0;
    // scanf("%lf", &num);
    // printf("input: %lf\t", num);

    // double v = log2(num);

    // if(ceil(v) == v){
    //   printf("yes");
    // }else{
    //   printf("no");
    // }

    int x = 0;
    scanf("%d", &x);
    printf("input: %d\t", x);
    if((x & (x - 1))) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    return 0;
}
