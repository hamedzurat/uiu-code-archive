#include <stdio.h>

int main() {
    int in = 65526374;
    scanf("%d", &in);

    int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0,
        seven = 0, eight = 0, nine = 0;

    while(in != 0) {
        int digit = in % 10;

        if(digit == 0)
            zero++;
        else if(digit == 1)
            one++;
        else if(digit == 2)
            two++;
        else if(digit == 3)
            three++;
        else if(digit == 4)
            four++;
        else if(digit == 5)
            five++;
        else if(digit == 6)
            six++;
        else if(digit == 7)
            seven++;
        else if(digit == 8)
            eight++;
        else if(digit == 9)
            nine++;

        in = in / 10;
    }

    if(zero != 0)
        printf("0 => %d\n", zero);
    if(one != 0)
        printf("1 => %d\n", one);
    if(two != 0)
        printf("2 => %d\n", two);
    if(three != 0)
        printf("3 => %d\n", three);
    if(four != 0)
        printf("4 => %d\n", four);
    if(five != 0)
        printf("5 => %d\n", five);
    if(six != 0)
        printf("6 => %d\n", six);
    if(seven != 0)
        printf("7 => %d\n", seven);
    if(eight != 0)
        printf("8 => %d\n", eight);
    if(nine != 0)
        printf("9 => %d\n", nine);

    return 0;
}
