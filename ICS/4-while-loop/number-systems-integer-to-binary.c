#include <math.h>
#include <stdio.h>

int main(void) {
    int input, output = 0;
    scanf("%d", &input);

    int i = input, j = 1;
    while(i != 0) {

        output = output + ((i % 2) * j);

        i = i / 2;
        j = j * 10;

        // printf("%d %d\n", i, output);
    }

    printf("%d\n", output);

    return 0;
}
