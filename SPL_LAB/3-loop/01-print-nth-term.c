#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++)
        printf("%d, ", i);

    return 0;
}
