#include <stdio.h>

int main(void) {
    int n = 0, r = 0, n_bang = 1, r_bang = 1, out = 0;
    scanf("%d %d", &n, &r);

    for(int i = 1; i <= n; i++)
        n_bang = n_bang * i;

    for(int i = 1; i <= (n - r); i++)
        r_bang = r_bang * i;

    out = n_bang / r_bang;
    printf("%d\n", out);

    return 0;
}
