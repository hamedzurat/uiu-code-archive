#include <stdio.h>

void print(int b[], int len) {
    for(int i = len - 1; i >= 0; i--)
        printf("%d ", b[i]);
}

int main(void) {
    int input;
    scanf("%d", &input);

    int a[input];
    for(int i = 0; i < input; i++)
        scanf("%d", &a[i]);

    print(a, input);

    return 0;
}
