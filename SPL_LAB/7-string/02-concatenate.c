#include <stdio.h>

#define MAX 100

int main(void) {

    char str1[MAX], str2[MAX], concat[MAX * 2];
    scanf("%[^\n]s", str1);
    getchar();  // to clear newline char
    scanf("%[^\n]s", str2);

    int count = 0;
    for(int i = 0; i < MAX; i++)
        if(str1[i] != '\0')
            count++;
        else
            break;

    for(int i = 0; i < count; i++)
        concat[i] = str1[i];
    for(int i = count, j = 0; i < MAX - count; i++, j++)
        concat[i] = str2[j];

    printf("%s", concat);

    return 0;
}
