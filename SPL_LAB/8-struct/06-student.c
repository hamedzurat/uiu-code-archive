#include <stdio.h>

struct student {
    char name[100];
    int id;
    double cgpa;
};

int main(void) {

    struct student one;

    scanf("%[^\n]s", one.name);
    getchar();
    scanf("%d %lf", &one.id, &one.cgpa);

    printf("name: %s\nid: %d\ncgpa: %lf\n", one.name, one.id, one.cgpa);

    return 0;
}
