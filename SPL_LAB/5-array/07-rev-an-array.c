#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    int array[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    for(int i = 0; i < input / 2; i++) {
        int tmp              = array[i];
        array[i]             = array[input - 1 - i];
        array[input - 1 - i] = tmp;
    }

    for(int i = 0; i < input; i++)
        printf("%d ", array[i]);

    return 0;
}
