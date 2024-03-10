#include <stdio.h>

int main(void) {

    int input, count = 0;
    scanf("%d", &input);

    char array[input];

    // scanf("%s", array);
    for(int i = 0; i < input; i++)
        scanf("%c", &array[i]);

    for(int i = 0; i < input; i++)
        if(array[i] == 'A' || array[i] == 'E' || array[i] == 'I' || array[i] == 'O' || array[i] == 'U')
            count++;

    printf("%d", count);

    return 0;
}
