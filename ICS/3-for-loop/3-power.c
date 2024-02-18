#include <stdio.h>

int main(void) {
    int a, n, out;
    scanf("%d %d", &a, &n);

    out = a;
    for(int i = 1; i < n; i++)
        out = out * a;

    printf("%d\n", out);

    return 0;
}
