#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);

    int i = input, j = 0;
    while(i != 0) {
        j = j * 10 + (i % 10);
        i = i / 10;

        // printf("%d %d\n", i, j);
    }

    if(input == j)
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;
}
