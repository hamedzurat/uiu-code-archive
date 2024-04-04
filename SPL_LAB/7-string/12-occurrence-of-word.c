#include <stdio.h>

#define MAX 100

int main(void) {

    char str[MAX], sub[MAX];
    scanf("%[^\n]s", str);
    getchar();
    scanf("%[^\n]s", sub);

    int count_str = 0;
    for(int i = 0; i < MAX; i++)
        if(str[i] != '\0')
            count_str++;
        else
            break;

    int count_sub = 0;
    for(int i = 0; i < MAX; i++)
        if(sub[i] != '\0')
            count_sub++;
        else
            break;

    int count = 0, flag = 0;

    for(int i = 0; i < count_str; i++) {
        for(int j = 0; j < count_sub; j++)
            if(str[i + j] != sub[j])
                flag = 1;

        if(flag == 0)
            count++;

        flag = 0;
    }

    printf("%d", count);

    return 0;
}
