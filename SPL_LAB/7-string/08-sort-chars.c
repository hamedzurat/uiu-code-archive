#include <stdio.h>

#define MAX 100

int main(void) {
    char str[MAX];
    scanf("%[^\n]s", str);

    int count = 0;
    for(int i = 0; i < MAX; i++)
        if(str[i] != '\0')
            count++;
        else
            break;

    for(int i = 0; i < count - 1; i++)
        for(int j = 0; j < count - 1; j++)
            if(str[j] > str[j + 1]) {
                char tmp   = str[j];
                str[j]     = str[j + 1];
                str[j + 1] = tmp;
            }

    printf("%s", str);

    return 0;
}
