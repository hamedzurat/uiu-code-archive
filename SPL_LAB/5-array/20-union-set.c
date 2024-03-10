#include <stdio.h>

int main(void) {
    int input1, input2, FLAG = 0;

    scanf("%d", &input1);
    int array1[input1];
    for(int i = 0; i < input1; i++)
        scanf("%d", &array1[i]);

    scanf("%d", &input2);
    int array2[input2];
    for(int i = 0; i < input2; i++)
        scanf("%d", &array2[i]);

    for(int i = 0; i < input1; i++)
        printf("%d ", array1[i]);

    for(int i = 0; i < input2; i++) {
        for(int j = 0; j < input1; j++)
            if(array2[i] == array1[j])
                FLAG = 1;

        if(FLAG != 1)
            printf("%d ", array2[i]);

        FLAG = 0;
    }

    return 0;
}
