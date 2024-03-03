#include <stdio.h>

int main() {
    int students;
    scanf("%d", &students);

    for(int i = 1; i <= students; i++) {
        double A, HW, CT, MT, TF, total;
        scanf("%lf %lf %lf %lf %lf", &A, &HW, &CT, &MT, &TF);

        total = A + HW + CT;
        total = total + (MT * 0.6);
        total = total + (TF * 0.4);

        if(total >= 90)
            printf("Student %d : A\n", i);
        else if(total >= 86)
            printf("Student %d : A-\n", i);
        else if(total >= 82)
            printf("Student %d : B+\n", i);
        else if(total >= 78)
            printf("Student %d : B\n", i);
        else if(total >= 74)
            printf("Student %d : B-\n", i);
        else if(total >= 70)
            printf("Student %d : C+\n", i);
        else if(total >= 66)
            printf("Student %d : C\n", i);
        else if(total >= 62)
            printf("Student %d : C-\n", i);
        else if(total >= 58)
            printf("Student %d : D+\n", i);
        else if(total >= 55)
            printf("Student %d : D\n", i);
        else
            printf("Student %d : F\n", i);
    }

    return 0;
}
