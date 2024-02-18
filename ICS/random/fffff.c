#include <stdio.h>

int main(void) {
    int in1, in2, in3, out = 0;
    scanf("%d %d %d", &in1, &in2, &in3);

    for(int i = in1; i <= in2; i++) {
        if((i % 2 != 0) || (i % in3 == 0)) {
            printf("%d\t", i);
            out = out + i;
        }
    }

    printf("\nsum: %d\n", out);

    return 0;
}
