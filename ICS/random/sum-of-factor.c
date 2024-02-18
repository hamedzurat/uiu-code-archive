#include <stdio.h>

int main(void) {
    int in = 0, out = 0;
    scanf("%d", &in);

    for(int i = 1; i <= in; i++) {
        if(in % i == 0) {
            out = out + i;
        }
    }

    printf("%d\n", out);

    return 0;
}
