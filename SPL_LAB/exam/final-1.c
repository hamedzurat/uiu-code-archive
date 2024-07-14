#include <stdio.h>

#define MAX 1000

void removeSpecialCharacters(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
        } else if(str[i] >= 'a' && str[i] <= 'z') {
        } else
            str[i] = ' ';
    }
}

char changeAlphabet(char alphabet) {
    if(alphabet >= 'A' && alphabet <= 'Z')
        return 'Z' - (alphabet - 'A');

    else if(alphabet >= 'a' && alphabet <= 'z')
        return 'z' - (alphabet - 'a');
}

void encoder(char* p) {
    removeSpecialCharacters(p);

    for(int i = 0; p[i] != '\0'; i++)
        if(p[i] != ' ')
            p[i] = changeAlphabet(p[i]);
}

int main() {
    char str[MAX];
    scanf("%[^\n]s", str);

    encoder(str);

    printf("%s\n", str);
    return 0;
}
