
#include <iostream>
using namespace std;

int SUM(int n) {
    return (n <= 0)
           ? 0
           : (n == 1)
             ? 2
             : SUM(n - 1) + (4 * n - 2);
}

int main() {
    int n = 4;
    int s = SUM(n);
    cout << s << endl;
    return 0;
}
