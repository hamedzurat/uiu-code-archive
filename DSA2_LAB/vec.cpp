#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> v = { 2.4, 4.3 };
    v.push_back(1.7);

    cout << "unsorted: " << endl;
    for(double x : v) cout << x << " ";
    cout << endl;

    // sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());

    cout << "sorted: " << endl;
    for(double x : v) cout << x << " ";
    cout << endl;

    return 0;
}
