#include <stdio.h>

int main(void) {
    int input, size;
    scanf("%d", &input);

    int array[input];
    size = input;

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(array[i] == array[j]) {
                for(int k = j; k < size - 1; k++)
                    array[j] = array[j + 1];

                size--;
                j--;
            }

    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}
