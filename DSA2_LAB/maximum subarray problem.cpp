#include <iostream>
#include <vector>
using namespace std;

struct subArray {
    int sum, low, high;
};

subArray maxCrossingSum(vector<int> a, int low, int mid, int high) {
    int sum = 0, left_sum = INT_MIN, l = -1;
    for(int i = mid; i >= low; i--) {
        sum += a[i];
        if(sum > left_sum) {
            left_sum = sum;
            l        = i;
        }
    }
    sum           = 0;
    int right_sum = INT_MIN, r = -1;
    for(int i = mid + 1; i <= high; i++) {
        sum += a[i];
        if(sum > right_sum) {
            right_sum = sum;
            r         = i;
        }
    }

    return { left_sum + right_sum, l, r };
}

subArray findMaxSubArray(vector<int> a, int low, int high) {
    if(low == high) return { low, high, a[low] };
    int mid = (low + high) / 2;
    // conquer
    subArray left  = findMaxSubArray(a, low, mid);
    subArray right = findMaxSubArray(a, mid + 1, high);
    // combine
    subArray cross = maxCrossingSum(a, low, mid, high);
    if(left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if(right.sum >= left.sum && right.sum >= cross.sum)
        return left;
    else
        return cross;
}

int main() {
    vector<int> arr = { -2, 5, -1, 2, 3, -7, 5 };
    int n           = arr.size();
    subArray sub    = findMaxSubArray(arr, 0, n - 1);
    int sum         = sub.sum;
    int low         = sub.low;
    int high        = sub.high;
    cout << "Max subarray sum: " << sum << endl;
    cout << "Max subarray: ";
    for(int i = low; i <= high; i++) cout << arr[i] << ",";
}
