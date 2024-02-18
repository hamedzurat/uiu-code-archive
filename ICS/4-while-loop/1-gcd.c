#include <stdio.h>

int main(void) {
    int input_1, input_2, output;
    scanf("%d %d", &input_1, &input_2);

    for(int i = 1; i <= input_1 && i <= input_2; ++i) {
        if((input_1 % i == 0) && (input_2 % i == 0)) {
            output = i;
        }
    }

    printf("%d\n", output);

    return 0;
}
