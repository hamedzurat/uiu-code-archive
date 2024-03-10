#include <stdio.h>

int main(void) {

    int input;
    scanf("%d", &input);

    for(int i = 1; i < input; i++) {
        for(int j = 1; j <= i; j++)
            printf("%d", j);
        for(int j = 1; j <= input - i; j++)
            printf("_");

        for(int j = 1; j <= input - i - 1; j++)
            printf("_");
        for(int j = i; j >= 1; j--)
            printf("%d", j);

        printf("\n");
    }
    for(int i = 1; i <= input; i++)
        printf("%d", i);
    for(int i = input - 1; i >= 1; i--)
        printf("%d", i);

    return 0;
}
