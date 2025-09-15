
#include <iostream>
using namespace std;

int th(int n) {
    return (n <= 0)
           ? 0
           : (n == 1 || n == 2)
             ? n
             : th(n - 1) + 3;
    //                    : 3*(n-1)-1;
}

int main() {
    int n = 4;
    int s = th(n);
    cout << s << endl;
    return 0;
}
