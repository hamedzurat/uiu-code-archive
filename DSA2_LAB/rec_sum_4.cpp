
#include <iostream>
using namespace std;

int SUM(int n) {
    return (n <= 0)
           ? 0
           : (n == 1)
             ? 3
             : SUM(n - 1) + (2 * n + 1);
}

int main() {
    int n = 4;
    int s = SUM(n);
    cout << s << endl;
    return 0;
}
