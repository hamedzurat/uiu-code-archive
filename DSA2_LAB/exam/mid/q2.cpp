#include <bits/stdc++.h>
using namespace std;

int DvC(int prices[], int budget, int low, int high) {
    if(low == high) return budget <= prices[low] ? -1 : prices[low];

    int mid = (low + high) / 2;
    int l   = DvC(prices, budget, low, mid);
    int r   = DvC(prices, budget, mid + 1, high);

    int ret;

    if(budget == l)
        ret = l;
    else if(budget == r)
        ret = r;
    else if(budget > l && l > r)
        ret = l;
    else if(budget > r && r > l)
        ret = r;
    else if(budget > r && budget > l)
        ret = l;
    else
        ret = -1;

    //    cout << ret << " = \t"<< r << "\t"<< l << endl;

    return ret;
}

int main() {
    int prices[] = { 1200, 1350, 1550, 1400, 1140, 3500, 850 };
    int budget   = 0;

    cout << "budget: ";
    cin >> budget;

    int maxx = DvC(prices, budget, 0, 7);

    if(maxx == 0 || maxx == -1)
        cout << "No gift is available within this budget" << endl;
    else
        cout << "Most expensive gift within budget: " << maxx << endl;

    return 0;
}
