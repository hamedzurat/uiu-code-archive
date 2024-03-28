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

int gen_Nth_prime(int input) {
    int ret, i = 2;
    while(1) {
        if(isprime(i) == 1) {
            input--;
            if(input == 0)
                return i;
        }
        i++;
    }
}

int main(void) {
    int input;
    scanf("%d", &input);

    printf("%d", gen_Nth_prime(input));

    return 0;
}
