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

void generate_prime(int input) {
    for(int i = 2; i < input; i++)
        if(isprime(i) == 1)
            printf("%d, ", i);
}

int main(void) {
    int input;
    scanf("%d", &input);

    generate_prime(input);

    return 0;
}
