#include <stdio.h>

int main(void) {
    double x, y;
    char op;
    scanf("%lf %c %lf", &x, &op, &y);

    if(op == '+')
        printf("%lf", x + y);
    else if(op == '-')
        printf("%lf", x - y);
    else if(op == '*')
        printf("%lf", x * y);
    else if(op == '/') {
        if(y == 0)
            printf("zero as divisor is not valid");
        else
            printf("%lf", x / y);
    }

    return 0;
}
