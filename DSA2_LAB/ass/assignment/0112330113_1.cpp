#include <bits/stdc++.h>
using namespace std;

struct sub {
    int size, low, high;
};

sub crossSubArray(vector<int>& p, int low, int mid, int high) {
    int r = 0, l = 0;
    for(int i = mid + 1; i <= high; i++) {
        if(p[i] < 0) break;
        ++l;
    }

    for(int i = mid; i >= low; i--) {
        if(p[i] < 0) break;
        ++r;
    }

    return { r + l, mid + 1 - l, mid + r };
}

sub longsubarray(vector<int>& p, int low, int high) {
    if(low == high) {
        if(p[low] > 0)
            return { 1, low, high };
        else
            return { 0, -1, -1 };
    }

    int mid = (low + high) / 2;
    sub l   = longsubarray(p, low, mid);
    sub r   = longsubarray(p, mid + 1, high);
    sub c   = crossSubArray(p, low, mid, high);

    if(l.size > c.size && l.size > r.size)
        return l;
    else if(r.size > c.size && r.size > l.size)
        return r;
    else
        return c;
}

int main() {
    vector<int> p = { 3, -1, 9, -2, 4, 3, 1, -5, 3, 2 };

    sub a = longsubarray(p, 0, p.size() - 1);

    cout << a.size << endl;
    for(int i = a.low + 1; i <= a.high + 1; ++i) cout << p[i] << ' ';
}
