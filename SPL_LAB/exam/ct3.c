#include <stdio.h>

// set - B

int SecondSmallest(int size, int a[size]) {
    int s1;  // smallest number
    int s2;  // second smallest number

    /*
        setting first 2 value of the array as the smallest and second smallest number
    */
    if(a[0] > a[1]) {
        s1 = a[1];
        s2 = a[0];
    } else {
        s1 = a[0];
        s2 = a[1];
    }

    /*
        starting from 2, because we already calculated for the index 0 and 1
    */
    for(int i = 2; i < size; i++) {
        /*
            if the current number is smaller than the smallest then
            its the new smallest
            and
            previous smallest is the second smallest
        */
        if(s1 > a[i]) {
            s2 = s1;
            s1 = a[i];
        } else if(s2 > a[i])  // if the current number is not smallest but smaller than the second smallest, then its the new second smallest now
            s2 = a[i];
    }

    return s2;
}

int main(void) {
    printf("SET - B\n\nenter the size: ");
    int input;
    scanf("%d", &input);

    int a[input];

    for(int i = 0; i < input; i++)
        scanf("%d", &a[i]);

    printf("second smallest number: %d\n",
    SecondSmallest(input, a));

    return 0;
}
