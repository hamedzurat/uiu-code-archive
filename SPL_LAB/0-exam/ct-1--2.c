#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        for(int j = 0; j < input - i - 1; j++)
            printf("_");

        for(int j = 0; j < (i * 2) + 1; j++)
            printf("%d", i + 1);

        printf("\n");
    }

    return 0;
}
