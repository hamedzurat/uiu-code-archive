#include <stdio.h>

int main(void) {
    int in = 0, out = 1;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        out = out * i;
    }

    printf("%d\n", out);

    return 0;
}
