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

    int FLAG = 0;
    for(int i = 0; i < count / 2; i++)
        if(str[i] != str[count - i - 1])
            FLAG = 1;

    if(FLAG == 0)
        printf("yes");
    else
        printf("no");

    return 0;
}
