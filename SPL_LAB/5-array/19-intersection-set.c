#include <stdio.h>

int main(void) {
    int input1, input2;

    scanf("%d", &input1);
    int array1[input1];
    for(int i = 0; i < input1; i++)
        scanf("%d", &array1[i]);

    scanf("%d", &input2);
    int array2[input2];
    for(int i = 0; i < input2; i++)
        scanf("%d", &array2[i]);

    for(int i = 0; i < input1; i++)
        for(int j = 0; j < input2; j++)
            if(array1[i] == array2[j])
                printf("%d ", array1[i]);

    return 0;
}
