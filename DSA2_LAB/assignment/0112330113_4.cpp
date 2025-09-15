#include <bits/stdc++.h>
using namespace std;

struct Result {
    int sum;
    int index;
};

Result crosss(vector<int>& arr, int low, int mid, int high) {
    int bestCrossSum = INT_MIN, index = -1;

    if(mid - 1 >= low && mid + 1 <= high) {
        int s = arr[mid - 1] + arr[mid] + arr[mid + 1];
        if(s > bestCrossSum) {
            bestCrossSum = s;
            index        = mid - 1;
        }
    }

    if(mid - 2 >= low) {
        int s = arr[mid - 2] + arr[mid - 1] + arr[mid];
        if(s > bestCrossSum) {
            bestCrossSum = s;
            index        = mid - 2;
        }
    }

    if(mid + 2 <= high) {
        int s = arr[mid] + arr[mid + 1] + arr[mid + 2];
        if(s > bestCrossSum) {
            bestCrossSum = s;
            index        = mid;
        }
    }

    return { bestCrossSum, index };
}

Result max3(vector<int>& arr, int low, int high) {
    if(high - low + 1 < 3) return { INT_MIN, -1 };
    if(high - low + 1 == 3) {
        int s = arr[low] + arr[low + 1] + arr[low + 2];
        return { s, low };
    }

    int mid = (low + high) / 2;

    Result l = max3(arr, low, mid);
    Result r = max3(arr, mid + 1, high);
    Result m = crosss(arr, low, mid, high);

    if(l.sum >= r.sum && l.sum >= m.sum) return l;
    if(r.sum >= l.sum && r.sum >= m.sum) return r;
    return m;
}

int main() {
    vector<int> arr = { 28, 31, 29, 34, 30, 33, 27, 35, 32 };
    Result res      = max3(arr, 0, arr.size() - 1);

    cout << arr[res.index] << ", " << arr[res.index + 1] << ", " << arr[res.index + 2] << endl;
    cout << "total = " << res.sum << endl;
    return 0;
}
