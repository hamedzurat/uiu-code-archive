#include <stdio.h>

#define MAX 100

int main(void) {
    char str[MAX], rev[MAX], word[MAX];
    scanf("%[^\n]s", str);

    int count = 0;
    for(int i = 0; i < MAX; i++)
        if(str[i] != '\0')
            count++;
        else
            break;

    int word_char = 0, offset = count + 1;
    for(int i = 0; i < count + 1; i++)
        if(str[i] != ' ' && str[i] != '\0')
            word[word_char++] = str[i];
        else {
            word[word_char] = '\0';

            offset -= word_char + 1;
            // printf("%s - %d -- %d\n", word, word_char, offset);

            for(int j = 0; j < word_char; j++)
                rev[offset + j] = word[j];

            rev[offset + word_char] = ' ';

            word_char = 0;
        }
    rev[count + 1] = '\0';

    printf("%s", rev);

    return 0;
}
