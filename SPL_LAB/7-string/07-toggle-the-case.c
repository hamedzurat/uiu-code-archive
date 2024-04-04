#include <stdio.h>

#define MAX 100

int main(void) {
    char str[MAX];
    scanf("%[^\n]s", str);

    for(int i = 0; i < MAX; i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';

    printf("%s", str);

    return 0;
}
