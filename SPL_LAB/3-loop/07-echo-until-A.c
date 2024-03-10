#include <stdio.h>

int main(void) {
    int i = 1;

    while(1) {
        char in;
        scanf("%c", &in);
        scanf("%c");

        if(in == 'A')
            break;
        else
            printf("input %d: %c\n", i++, in);
    }

    return 0;
}
