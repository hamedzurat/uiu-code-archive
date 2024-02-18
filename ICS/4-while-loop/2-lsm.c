#include <stdio.h>

int main(void) {
    int input_1, input_2, i, output;
    scanf("%d %d", &input_1, &input_2);

    if(input_1 > input_2)
        i = input_1;
    else
        i = input_2;

    for(;; ++i) {
        if((i % input_1 == 0) && (i % input_2 == 0)) {
            output = i;
            break;
        }
    }

    printf("%d\n", output);

    return 0;
}
