#include <stdio.h>

int main(void) {
    int input, pos, num;
    scanf("%d", &input);

    int array[input + 1];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    scanf("%d %d", &num, &pos);

    for(int i = input; i > pos; i--)
        array[i] = array[i - 1];

    array[pos] = num;

    for(int i = 0; i < input + 1; i++)
        printf("%d ", array[i]);

    return 0;
}
