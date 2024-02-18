#include <stdio.h>

int main(void) {
    int in;
    double out = 0;

    scanf("%d", &in);

    for(int i = 1; i <= in; i++)
        out = out + (1.0 / i);

    printf("%lf\n", out);
    return 0;
}
