#include <stdio.h>

int main(void) {
    int raw = 0;
    scanf("%d", &raw);
    printf("input: %d\t", raw);

    if(raw > 100 || raw < 0)
        printf("u ok ???\n");
    else if(raw >= 90)
        printf("grade: A\n");
    else if(raw >= 86)
        printf("grade: A-\n");
    else if(raw >= 82)
        printf("grade: B+\n");
    else if(raw >= 78)
        printf("grade: B\n");
    else if(raw >= 74)
        printf("grade: B-\n");
    else if(raw >= 70)
        printf("grade: C+\n");
    else if(raw >= 66)
        printf("grade: C\n");
    else if(raw >= 62)
        printf("grade: C-\n");
    else if(raw >= 58)
        printf("grade: D+\n");
    else if(raw >= 55)
        printf("grade: D\n");
    else
        printf("time for retake\n");

    return 0;
}
