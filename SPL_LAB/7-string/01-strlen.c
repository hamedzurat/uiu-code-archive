#include <stdio.h>

#define MAX 100

int main(void) {

    char string[MAX];
    scanf("%[^\n]s", string);

    int count = 0;

    for(int i = 0; i < MAX; i++)
        if(string[i] != '\0')
            count++;
        else
            break;

    printf("%d", count);

    return 0;
}
