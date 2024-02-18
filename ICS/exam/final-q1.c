#include <stdio.h>

int main() {
    int L1 = 0, L2 = 0;

    while(1) {
        int in1, in2;

        printf("Enter the first number: ");
        scanf("%d", &in1);
        printf("Enter the second number: ");
        scanf("%d", &in2);

        if(in1 == in2)
            break;

        if(L1 < in1) {
            L2 = L1;
            L1 = in1;
        } else if(L2 < in1)
            L2 = in1;

        if(L1 < in2) {
            L2 = L1;
            L1 = in2;
        } else if(L2 < in2)
            L2 = in2;
    }

    printf("%d\n", L1 + L2);

    return 0;
}
