#include <iostream>
using namespace std;

int SUM(int n) {
    return (n <= 0)
           ? 0
           : (n == 1)
             ? 1
             : SUM(n - 3) + n;
}

int main() {
    int n = 10;
    int s = SUM(n);
    cout << s << endl;
    return 0;
}
