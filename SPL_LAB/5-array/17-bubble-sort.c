#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    int array[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    for(int j = 0; j < input; j++) {
        for(int i = 0; i < input - 1; i++) {
            if(array[i] > array[i + 1]) {
                int tmp      = array[i];
                array[i]     = array[i + 1];
                array[i + 1] = tmp;
            }
        }
    }

    for(int i = 0; i < input; i++)
        printf("%d ", array[i]);

    return 0;
}
