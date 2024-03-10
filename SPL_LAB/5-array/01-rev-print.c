#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    int array[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    for(int i = input; i > 0; i--)
        printf("%d ", array[i - 1]);

    return 0;
}
