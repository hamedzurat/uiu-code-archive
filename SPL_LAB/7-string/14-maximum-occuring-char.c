#include <stdio.h>

#define MAX 100

int main(void) {
    char str[MAX];
    scanf("%[^\n]s", str);

    int counter['Z' - 'A' + 1] = { 0 };

    int count = 0;
    for(int i = 0; i < MAX; i++)
        if(str[i] != '\0')
            count++;
        else
            break;

    for(int i = 0; i < count; i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            counter[str[i] - 'A']++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            counter[str[i] - 'a']++;

    // for(int i = 0; i < 'z' - 'a' + 1; i++)
    //     printf("%c - %d\n", i + 'a', counter[i]);

    int big = 0;
    for(int i = 0; i < 'z' - 'a' + 1; i++)
        if(counter[i] > counter[big])
            big = i;

    printf("%c (or %c)", 'A' + big, 'a' + big);

    return 0;
}
