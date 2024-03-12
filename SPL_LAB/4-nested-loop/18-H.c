#include <stdio.h>

int main(void) {
    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        printf("H");

        if(i == (input / 2))
            for(int j = 0; j < input - 2; j++)
                printf("H");
        else
            for(int j = 0; j < input - 2; j++)
                printf(" ");

        printf("H\n");
    }

    return 0;
}
