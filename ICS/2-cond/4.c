#include <stdio.h>

int main(void) {
    int raw1 = 0;
    int raw2 = 0;
    int raw3 = 0;
    scanf("%d %d %d", &raw1, &raw2, &raw3);
    printf("input: %d %d %d\t", raw1, raw2, raw3);

    int ang = raw1 + raw2 + raw3;

    if(raw1 == 0 || raw2 == 0 || raw3 == 0 || raw1 == 180 || raw2 == 180 ||
       raw3 == 180 || ang != 180) {
        printf("no");
    } else {
        printf("yes");
    }

    return 0;
}
