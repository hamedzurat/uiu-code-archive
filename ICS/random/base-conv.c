#include <math.h>
#include <stdio.h>

// this code only works for base 2 to 10
// as far as i know
// for base 16 you need the help of array

int main(void) {
    int in, in_base, out_base, mid = 0, output = 0;
    scanf("%d %d %d", &in, &in_base, &out_base);

    int i = in, j = 0;
    while(i != 0) {

        mid = mid + ((i % 10) * pow(in_base, j));

        i = i / 10;
        j++;
    }

    i = mid, j = 1;
    while(i != 0) {

        output = output + ((i % out_base) * j);

        i = i / out_base;
        j = j * 10;
    }

    printf("%d\n", output);

    return 0;
}
