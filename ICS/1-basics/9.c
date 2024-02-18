#include <stdio.h>

int main(void) {
    // printf("centimeters: ");
    int raw = 0;
    scanf("%d", &raw);
    printf("input: %d\n", raw);

    int meter = raw / 100;
    int cen   = raw % 100;
    printf("%d meter %d centmeter\n", meter, cen);
    return 0;
}
