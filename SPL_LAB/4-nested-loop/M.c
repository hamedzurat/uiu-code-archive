#include <stdio.h>

int main(void) {

    int input = 5;
    scanf("%d", &input);

    for(int i = 0; i < input; i++) {
        printf("*");

        if(i == 0)
            for(int j = 0; j < input - 2; j++)
                printf(" ");

        else if(i < (1 + (input / 2))) {

            for(int j = 0; j < i - 1; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < (input - ((i + 1) * 2)); j++)
                printf(" ");

            if(((input / 2)) != i)
                printf("*");

            for(int j = 0; j < i - 1; j++)
                printf(" ");

        } else
            for(int j = 0; j < input - 2; j++)
                printf(" ");

        printf("*\n");
    }

    return 0;
}

// #include <stdio.h>

// int main() {
//     int n;

//     scanf("%d", &n);

//     for(int i = 1; i <= n / 2 + 1; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(j == 1 || j == n || i == j || i + j == n + 1) {
//                 printf("*");
//             } else {
//                 printf(" ");
//             }
//         }

//         printf("\n");
//     }
//     for(int i = 1; i <= n / 2; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(j == 1 || j == n) {
//                 printf("*");
//             } else {
//                 printf(" ");
//             }
//         }

//         printf("\n");
//     }
// }
