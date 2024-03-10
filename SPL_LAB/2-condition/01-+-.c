#include <stdio.h>

int main(void) {
    double in;
    scanf("%lf", &in);

    if(in >= 0)
        printf("positive");
    else
        printf("negative");

    return 0;
}
