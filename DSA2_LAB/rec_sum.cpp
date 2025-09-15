#include <iostream>
using namespace std;

int SUM(int n) {
    //    if (n<=0) return 0;
    //    else if(n==1) return 1;
    //    else return SUM(n-1) + n;

    return (n <= 0) ? 0 : (n == 1) ? 1
                                   : SUM(n - 1) + n;
}

int main() {
    int n = 4;
    int s = SUM(n);
    cout << s << endl;
    return 0;
}
