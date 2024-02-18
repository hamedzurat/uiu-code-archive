#include <stdio.h>

int main(void) {
    // printf("inches: ");
    int inches = 0;
    scanf("%d", &inches);
    printf("input: %d\n", inches);

    int feet = inches / 12;
    int inch = inches % 12;
    printf("%d feet %d inch\n", feet, inch);
    return 0;
}
