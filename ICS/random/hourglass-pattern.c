#include <stdio.h>

int main(void) {
    int in;
    scanf("%d", &in);

    /*
      in my solution inout 2 and 3 outputs the same
      i dont know if its the right way or not
    */

    for(int i = 1; i <= (in / 2) + 1; i++) {
        for(int j = 1; j < i; j++)
            printf(" ");

        for(int j = 0; j <= ((in / 2) + 1 - i); j++)
            printf("* ");

        printf("\n");
    }
    for(int i = 1; i <= (in / 2); i++) {
        for(int j = 1; j < ((in / 2) - i + 1); j++)
            printf(" ");

        for(int j = 0; j <= i; j++)
            printf("* ");

        printf("\n");
    }

    return 0;
}
