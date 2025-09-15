#include <iostream>
using namespace std;

int car(int rectangle, int circle, int triangle) {
    if(rectangle < 2 || circle < 3 || triangle < 1)
        return 0;
    else
        return 1 + car(rectangle - 2, circle - 3, triangle - 1);
}

int main() {
    int rectangle = 5, circle = 6, triangle = 5;
    int c = car(rectangle, circle, triangle);
    cout << c << endl;
    return 0;
}
