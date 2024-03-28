#include <stdio.h>

void input_matrix(int x, int y, int a[x][y]) {
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            scanf("%d", &a[i][j]);
}

void show_matrix(int x, int y, int a[x][y]) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

void scalar_multiply(int x, int y, int a[x][y], int num) {
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            a[i][j] = a[i][j] * num;
}

int main(void) {
    int x, y, num;
    scanf("%d %d", &x, &y);

    int a[x][y];

    input_matrix(x, y, a);

    scanf("%d", &num);

    printf("original:\n");
    show_matrix(x, y, a);

    scalar_multiply(x, y, a, num);

    printf("multipleid by %d:\n", num);
    show_matrix(x, y, a);

    return 0;
}
