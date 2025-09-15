#include <iostream>
using namespace std;

int step(int n) {
    //    if(n==0) return 1;
    //    else if(n<0) return 0;
    //    else return step(n-1) + step(n-2);

    return (n < 1)
           ? 0
           : (n == 1 || n == 2)
             ? n
             : step(n - 1) + step(n - 2);
}

int main() {
    int n = 4;
    int s = step(n);
    cout << s << endl;
    return 0;
}
