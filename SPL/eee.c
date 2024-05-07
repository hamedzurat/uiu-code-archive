#include <stdio.h>
#include <string.h>

int main(void) {
    char b[8] = "1234567890";
    char c[8] = "university";
    char d[8] = "0987654321";

    printf("%zu\n", sizeof(c));
    printf("%d\n", strlen(c));
    printf("%s\n", c);
    printf("%x %x %x \n", &b, &c, &d);

    for(int i = -10; i < 20; i++)
        printf("%d-%d:%c\n", i, c[i], c[i]);

    return 0;
}
