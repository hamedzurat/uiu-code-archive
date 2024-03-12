#include <stdio.h>

int main(void) {
    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        printf("*");

        if(i == 0)
            for(int j = 0; j < input - 2; j++)
                printf("*");
        else if(i == (input / 2) && input != 3)
            for(int j = 0; j < input - 2; j++)
                printf("*");
        else if(i == (input - 1))
            for(int j = 0; j < input - 2; j++)
                printf("*");
        else
            for(int j = 0; j < input - 2; j++)
                printf("-");

        printf("*\n");
    }

    return 0;
}
