#include <stdio.h>

int main(void) {
    char ch;
    scanf("%c", &ch);

    if((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
        printf("alphabet");
    else if(ch > 47 && ch < 58)
        printf("digit");
    else
        printf("special");

    return 0;
}
