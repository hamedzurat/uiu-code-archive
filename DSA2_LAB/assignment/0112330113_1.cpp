#include <bits/stdc++.h>
using namespace std;

struct sub {
    int length, low, high;
};

sub crossSubArray(vector<int>& a, int low, int mid, int high) {
    int L = 0, R = 0;
    sub cross;

    for(int i = mid; i >= low; i--) {
        if(a[i] > 0)
            L++;
        else
            break;
    }

    for(int i = mid + 1; i <= high; i++) {
        if(a[i] > 0)
            R++;
        else
            break;
    }

    cross.length = L + R;
    cross.low    = mid + 1 - L;
    cross.high   = mid + R;

    return cross;
}

sub longsubarray(vector<int>& a, int low, int high) {
    if(low == high) {
        sub base;

        if(a[low] > 0) {
            base.length = 1;
            base.low = base.high = high;
        } else {
            base.length = 0;
            base.low = base.high = -1;
        }

        return base;
    }

    int mid = (low + high) / 2;
    sub l   = longsubarray(a, low, mid);
    sub r   = longsubarray(a, mid + 1, high);
    sub c   = crossSubArray(a, low, mid, high);

    if(l.length >= r.length && l.length >= c.length)
        return l;
    else if(r.length >= l.length && r.length >= c.length)
        return r;
    else
        return c;
}

int main() {
    vector<int> p = { 3, -1, 9, -2, 4, 3, 1, -5, 3, 2 };

    sub a = longsubarray(p, 0, p.size() - 1);

    cout << a.length << endl;
    for(int i = a.low; i <= a.high; i++) cout << i + 1 << " ";
}
