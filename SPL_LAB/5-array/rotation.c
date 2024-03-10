// The code repeatedly reads a degree of rotation, shifts elements in an array by that degree, and prints the rotated array until a degree of 0 is entered.

#include <stdio.h>

int main(void) {
    int input, degree;
    scanf("%d", &input);

    int array[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array[i]);

    while(1) {
        scanf("%d", &degree);

        if(degree == 0)
            break;

        for(int j = 0; j < degree; j++) {
            int tmp = array[0];

            for(int i = 0; i < input - 1; i++)
                array[i] = array[i + 1];

            array[input - 1] = tmp;
        }

        for(int i = 0; i < input; i++)
            printf("%d ", array[i]);

        printf("\n");
    }

    return 0;
}
