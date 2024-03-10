#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    int array1[input], array2[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &array1[i]);
    for(int i = 0; i < input; i++)
        scanf("%d", &array2[i]);

    for(int i = 0; i < input; i++)
        printf("%d ", array1[i] + array2[i]);

    return 0;
}
