#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    if(in % 2 == 0)
        printf("even");
    else
        printf("odd");

    return 0;
}
