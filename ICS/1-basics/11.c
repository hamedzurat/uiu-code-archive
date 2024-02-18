#include <stdio.h>

int main(void) {
    // printf("seconds: ");
    int raw = 0;
    scanf("%d", &raw);
    printf("input: %d\n", raw);

    int hours  = 0;
    int minute = 0;
    int second = 0;

    hours  = raw / 3600;
    minute = (raw % 3600) / 60;
    second = (raw % 3600) % 60;

    printf("%d hour %d minute %d secound\n", hours, minute, second);
    return 0;
}
