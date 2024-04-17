#include <stdio.h>

struct triangle {
    int id;
    double base;
    double height;
    double area;
};

int main(void) {

    struct triangle tri[3];
    int big = 0;

    for(int i = 0; i < 3; i++) {
        scanf("%d %lf %lf", &tri[i].id, &tri[i].base, &tri[i].height);
        tri[i].area = (tri[i].base * tri[i].height) / 2;
    }

    for(int i = 1; i < 3; i++)
        if(tri[big].area < tri[i].area)
            big = i;

    printf("area of %d = %lf\n", tri[big].id, tri[big].area);

    return 0;
}
