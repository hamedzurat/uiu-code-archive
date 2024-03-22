/*
mid-2.c asked to move all zeros to the left.
but, this one moves zeros to the right.
*/

#include <stdio.h>

int main(void) {

    int input;
    scanf("%d", &input);
    int a[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &a[i]);

    int in = input;
    for(int i = 0; i < in; i++)
        if(a[i] == 0) {
            for(int j = i; j < in - 1; j++) {
                int tmp  = a[j + 1];
                a[j + 1] = a[j];
                a[j]     = tmp;
            }
            i--;
            in--;
        }

    for(int i = 0; i < input; i++)
        printf("%d ", a[i]);

    return 0;
}

// #include <stdio.h>

// int main() {

//     int input, tmp;
//     scanf("%d", &input);
//     int a[input];

//     for(int i = 0; i < input; i++)
//         scanf("%d", &a[i]);

//     for(int i = 0; i < input; i++) {
//         for(int j = i + 1; j < input; j++) {
//             if(a[i] == 0 && a[j] > 0) {
//                 tmp  = a[i];
//                 a[i] = a[j];
//                 a[j] = tmp;
//             }
//         }
//     }
//     for(int i = 0; i < input; i++)
//         printf("%d ", a[i]);

//     return 0;
// }
