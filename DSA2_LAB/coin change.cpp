#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = { 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int amount        = 2891;

    for(int c : coins) {
        if(amount == 0) break;
        int n = amount / c;
        amount -= (n * c);
        if(n) cout << c << "\tx " << n << "\t= " << n * c << endl;
    }

    return 0;
}
