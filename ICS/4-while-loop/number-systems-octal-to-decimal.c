#include <stdio.h>

int main(void) {
    int input, output = 0;
    scanf("%d", &input);

    int i = input, j = 0;
    while(i != 0) {

        output = output + ((i % 10) * pow(8, j));

        i = i / 10;
        j++;

        // printf("%d %d\n", i, output);
    }

    printf("%d\n", output);

    return 0;
}
