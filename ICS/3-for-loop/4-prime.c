#include <stdio.h>

int main(void) {
    int in = 0, prime = 1;
    scanf("%d", &in);
    // printf("%d ", in);

    if(in <= 1)
        prime = 0;
    else if(in == 2)
        prime = 1;
    else if((in % 2) == 0)
        prime = 0;
    else {
        for(int i = 3; i <= in / 2; i = i + 2) {
            if((in % i) == 0) {
                prime = 0;
                break;
            }
        }
    }

    if(prime == 1)
        printf("Prime\n");
    else
        printf("Not prime\n");

    return 0;
}
