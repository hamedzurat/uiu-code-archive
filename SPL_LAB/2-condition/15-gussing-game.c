#include <stdio.h>

int main(void) {
    int p1 = 0, p2 = 0;
    scanf("%d", &p1);

    // 1st try
    scanf("%d", &p2);
    if(p2 == p1) {
        printf("Right, Player-2 wins!\n");
    } else {
        printf("Wrong, 2 Chance(s) Left!\n");

        // 2nd try
        scanf("%d", &p2);
        if(p2 == p1) {
            printf("Right, Player-2 wins!\n");
        } else {
            printf("Wrong, 1 Chance(s) Left!\n");

            // 3rd try
            scanf("%d", &p2);
            if(p2 == p1) {
                printf("Right, Player-2 wins!\n");
            } else {
                printf("Wrong, 0 Chance(s) Left!\n");
                printf("Player-1 wins!\n");
            }
        }
    }
}
