#include <stdio.h>

int main(void) {
    int input, sum = 0, FLAG = 0;
    scanf("%d", &input);

    while(input != 0) {
        int i = input % 10;
        input = input / 10;

        if(i % 2 == 0)
            FLAG = 1;

        sum = sum + i;
    }

    if(sum % 2 == 0)
        FLAG = 1;

    if(FLAG == 1)
        printf("Not a Wizard Number\n");
    else
        printf("Wizard Number\n");

    return 0;
}
