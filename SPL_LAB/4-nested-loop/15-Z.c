#include <stdio.h>

int main(void) {
    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        if(i == 0)
            for(int j = 0; j < input; j++)
                printf("Z");
        else if(i == (input - 1))
            for(int j = 0; j < input; j++)
                printf("Z");
        else {
            for(int j = 0; j < input - 1 - i; j++)
                printf(" ");
            printf("Z\n");
        }

        printf("\n");
    }

    return 0;
}
