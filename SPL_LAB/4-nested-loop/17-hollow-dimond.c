#include <stdio.h>

int main(void) {
    int input = 9;
    scanf("%d", &input);

    for(int i = 0; i < input / 2; i++) {
        for(int j = 1; j <= input; j++)
            if(j == (input / 2 + 1) || j == ((input / 2 + 1) - i) || j == ((input / 2 + 1) + i))
                printf("$");
            else
                printf("-");

        printf("\n");
    }

    for(int i = 0; i < input; i++)
        printf("$");
    printf("\n");

    for(int i = input / 2 - 1; i >= 0; i--) {
        for(int j = 1; j <= input; j++)
            if(j == (input / 2 + 1) || j == ((input / 2 + 1) - i) || j == ((input / 2 + 1) + i))
                printf("$");
            else
                printf("-");

        printf("\n");
    }

    return 0;
}
