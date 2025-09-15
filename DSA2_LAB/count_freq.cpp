#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = { 5, 1, 21, 6, 5, 16, 21, 5, 1 };
    map<int, int> nums;

    for(auto x : arr) {
        nums[x]++;
    }

    cout << "freq: " << endl;

    for(auto i : nums)
        cout << i.first << " -> " << i.second << endl;

    return 0;
}
