#include <stdio.h>

int main(void) {
    double in;
    scanf("%lf", &in);

    if(in > 100)
        printf("AAAAAAAAAAAAAAAAAAAAAAAA");
    else if(in >= 90)
        printf("A");
    else if(in >= 86)
        printf("A-");
    else if(in >= 82)
        printf("B+");
    else if(in >= 78)
        printf("B");
    else if(in >= 74)
        printf("B-");
    else if(in >= 70)
        printf("C+");
    else if(in >= 66)
        printf("C");
    else if(in >= 62)
        printf("C+");
    else if(in >= 58)
        printf("D+");
    else if(in >= 55)
        printf("D");
    else
        printf("F");

    return 0;
}
