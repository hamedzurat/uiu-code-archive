#include <stdio.h>

int isprime(int i) {

    if(i < 2)
        return 0;
    else if(i == 2)
        return 1;
    else if(i % 2 == 0)
        return 0;
    else
        for(int j = 3; j < i / 2; j++)
            if(i % j == 0)
                return 0;

    return 1;
}

int main(void) {
    int input;
    scanf("%d", &input);

    if(isprime(input) == 1)
        printf("Prime");
    else
        printf("Not prime");

    return 0;
}
