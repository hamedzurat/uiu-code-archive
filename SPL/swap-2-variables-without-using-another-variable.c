#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Print initial values
    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Step 1: Add a and b and store in a
    a = a + b;  // a becomes 15 (a + b)

    // Step 2: Subtract b from a and store in b
    b = a - b;  // b becomes 5 (a - b)

    // Step 3: Subtract b from a and store in a
    a = a - b;  // a becomes 10 (a - b)

    // Print final values
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
