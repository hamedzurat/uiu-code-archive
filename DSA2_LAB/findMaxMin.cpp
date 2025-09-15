#include <iostream>
using namespace std;

void FindMinMax(int a[], int i, int j, int& fmax, int& fmin) {
    if(i == j) {
        fmax = fmin = a[i];
        return;
    }
    if(i == j - 1) {
        fmax = max(a[i], a[j]);
        fmin = min(a[i], a[j]);
        return;
    }
    int mid = (i + j) / 2;
    int gmax, gmin, hmax, hmin;
    FindMinMax(a, i, mid, gmax, gmin);
    FindMinMax(a, mid + 1, j, hmax, hmin);
    fmax = max(gmax, hmax);
    fmin = min(gmin, hmin);
}

int main() {
    int a[] = { 14, 3, 6, 32, 7, 87, 9 };
    int fmax, fmin;
    int n = sizeof(a) / sizeof(a[0]);
    FindMinMax(a, 0, n - 1, fmax, fmin);
    cout << "max:" << fmax << " min:" << fmin;
}
