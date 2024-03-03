#include <stdio.h>

int main(void) {
    int in;
    double sum = 0;
    scanf("%d", &in);

    for(int i = 0; i < in; i++) {
        double num;
        scanf("%lf", &num);

        sum = sum + num;
    }

    printf("%lf", sum / in);

    return 0;
}
