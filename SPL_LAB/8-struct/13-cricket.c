#include <stdio.h>

struct player {
    char name[100];
    char country[100];
    int runs[3];
    int wickets[3];
    int points[3];
};

int main(void) {

    struct player p[2];

    for(int i = 0; i < 2; i++) {
        scanf("%[^\n]s", p[i].name);
        getchar();
        scanf("%[^\n]s", p[i].country);

        for(int j = 0; j < 3; j++)
            scanf("%d", &p[i].runs[j]);


        for(int j = 0; j < 3; j++)
            scanf("%d", &p[i].wickets[j]);

        getchar();
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            p[i].points[j] = 0;

            if(p[i].runs[j] <= 25)
                p[i].points[j] += 5;
            else if(p[i].runs[j] <= 50)
                p[i].points[j] += 10;
            else if(p[i].runs[j] <= 75)
                p[i].points[j] += 15;
            else
                p[i].points[j] += 20;

            p[i].points[j] += p[i].wickets[j] * 12;
        }
    }

    for(int i = 0; i < 3; i++) {
        printf("match: %d\n", i + 1);

        for(int j = 0; j < 2; j++)
            printf("%s: %d\n", p[j].name, p[j].points[i]);


        if(p[0].points[i] > p[1].points[i])
            printf("MOM: %s\n", p[0].name);
        else
            printf("MOM: %s\n", p[1].name);
    }

    if((p[0].points[0] + p[0].points[1] + p[0].points[2]) >
       (p[1].points[0] + p[1].points[1] + p[1].points[2]))
        printf("Man of the series: %s", p[0].name);
    else
        printf("Man of the series: %s", p[1].name);

    return 0;
}
