#include <math.h>
#include <stdio.h>

int main(void) {
    double input_1 = 0, input_2 = 0;
    int op = 0;

    scanf("%lf %lf", &input_1, &input_2);
    scanf("%d", &op);

    if(op == 1) {
        printf("addition: %lf\n", input_1 + input_2);
    } else if(op == 2) {
        printf("subtraction: %lf\n", input_1 - input_2);
    } else if(op == 3) {
        printf("multiplication: %lf\n", input_1 * input_2);
    } else if(op == 4) {
        if(input_2 == 0) {
            printf("Error: Divisor is zero\n");
        } else {
            int op2 = 0;
            scanf("%d", &op2);

            if(op2 == 1) {
                // printf("quotient: %lf\n", round(input_1 / input_2));
                printf("quotient: %d\n", (int)(input_1 / input_2));
            } else if(op2 == 2) {
                printf("reminder: %lf\n", remainder(input_1, input_2));
                printf("reminder: %lf\n", fmod(input_1, input_2));
            } else {
                printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
            }
        }
    } else {
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
    }
    return 0;
}
