#include <stdio.h>

int main(void) {

    int input = 8;
    scanf("%d", &input);
    int a[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < input; i++)
        if(a[i] == 0)
            for(int j = i; j >= 0; j--) {
                int tmp  = a[j - 1];
                a[j - 1] = a[j];
                a[j]     = tmp;
            }

    for(int i = 0; i < input; i++)
        printf("%d ", a[i]);

    return 0;
}
