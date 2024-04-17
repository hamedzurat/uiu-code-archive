#include <stdio.h>

struct triangle {
    int id;
    double base;
    double height;
};

int main(void) {

    struct triangle tri[3];

    for(int i = 0; i < 3; i++)
        scanf("%d %lf %lf", &tri[i].id, &tri[i].base, &tri[i].height);

    for(int i = 0; i < 3; i++)
        printf("area of %d = %lf\n", tri[i].id, (tri[i].base * tri[i].height) / 2);

    return 0;
}
