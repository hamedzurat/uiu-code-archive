#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    for(int i = 1; i <= in * 2; i = i + 2)
        printf("%d, ", i);

    return 0;
}
