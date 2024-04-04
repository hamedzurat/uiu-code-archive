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

    for(int i = 0; i < count; i++)
        for(int j = i + 1; j < count; j++)
            if(str[i] == str[j])
                for(int k = j; k < count; k++)
                    str[k] = str[k + 1];

    printf("%s", str);

    return 0;
}
