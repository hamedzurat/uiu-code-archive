#include <stdio.h>

int main(void) {
    int max = 0, min = 0;

    int input;
    scanf("%d", &input);

    int array[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    for(int i = 1; i < input; i++) {
        if(array[max] < array[i])
            max = i;
        if(array[min] > array[i])
            min = i;
    }

    printf("max: %d, index: %d\n", array[max], max);
    printf("min: %d, index: %d\n", array[min], min);

    return 0;
}
