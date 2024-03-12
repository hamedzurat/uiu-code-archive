#include <stdio.h>

int main(void) {

    int n   = 7;
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    // int n = 5;
    // int a[] = {10, 20, 30, 40, 50};
    // int n = 3;
    // int a[] = {9, 8, 7};

    for(int i = 0; i < n / 2 - 1; i++) {
        int tmp          = a[i];
        a[i]             = a[n / 2 - 1 - i];
        a[n / 2 - 1 - i] = tmp;
    }

    for(int i = n - 1; i > n / 2 + 1; i--) {
        int tmp          = a[i];
        a[i]             = a[n / 2 - i + n];
        a[n / 2 - i + n] = tmp;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
