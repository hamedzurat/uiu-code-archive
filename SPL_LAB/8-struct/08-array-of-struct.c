#include <stdio.h>

struct student {
    char name[100];
    int id;
    double cgpa;
};

int main(void) {

    struct student ppl[2];

    for(int i = 0; i < 2; i++) {
        scanf("%[^\n]s", ppl[i].name);
        scanf("%d", &ppl[i].id);
        scanf("%lf", &ppl[i].cgpa);
        getchar();
    }

    if(ppl[0].cgpa > ppl[1].cgpa)
        printf("name: %s\nid: %d\ncgpa: %lf\n", ppl[0].name, ppl[0].id, ppl[0].cgpa);
    else
        printf("name: %s\nid: %d\ncgpa: %lf\n", ppl[1].name, ppl[1].id, ppl[1].cgpa);

    return 0;
}
