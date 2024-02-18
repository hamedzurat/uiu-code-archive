#include <math.h>
#include <stdio.h>

int main(void) {
    double x, y;
    int op;
    scanf("%lf %lf", &x, &y);
    scanf("%d", &op);

    if(op == 1)
        printf("%lf", x + y);
    else if(op == 2)
        printf("%lf", x - y);
    else if(op == 3)
        printf("%lf", x * y);
    else if(op == 4) {
        if(y == 0) {
            printf("divisor is zero");
        } else {
            int op2;
            scanf("%d", &op2);

            if(op2 == 1) {
                if((x / y) > 0)
                    printf("%lf", floor(x / y));
                else
                    printf("%lf", ceil(x / y));
            } else if(op2 == 2) {
                // printf("%lf", remainder(x, y));

                if((x / y) > 0)
                    printf("%lf", x - (floor(x / y) * y));
                else
                    printf("%lf", x - (ceil(x / y) * y));
            } else
                printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
        }
    } else
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");

    return 0;
}
