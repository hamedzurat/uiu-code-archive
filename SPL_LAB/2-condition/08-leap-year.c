#include <stdio.h>

int main(void) {
    int year, LEAP;
    scanf("%d", &year);

    if(year % 400 == 0)
        LEAP = 1;
    else if(year % 100 == 0)
        LEAP = 0;
    else if(year % 4 == 0)
        LEAP = 1;
    else
        LEAP = 0;

    if(LEAP == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}
