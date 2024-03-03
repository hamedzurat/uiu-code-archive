#include <stdio.h>

int main(void) {
    int p1, try;
    scanf("%d", &p1);
    scanf("%d", &try);

    for(int i = 1; i <= try; i++) {
        int p2;
        scanf("%d", &p2);

        if(p1 == p2) {
            printf("Right, Player-2 wins!\n");
            break;
        } else
            printf("Wrong, %d Chance(s) Left!\n", try - i);
    }

    return 0;
}
