#include <bits/stdc++.h>
using namespace std;

class Choco {
    public:
    string name;
    int amount, totalPrice;
    double perChocolate;

    Choco(string n, int a, int p) : name(n), amount(a), totalPrice(p), perChocolate(p / a) {};
    void display() {
        cout << "chocolate: " << name << ", \tamount: " << amount << ", \tprice: " << totalPrice << ", \tunit_price: " << perChocolate << endl;
    }
};

bool compare(Choco c1, Choco c2) {
    return c1.perChocolate < c2.perChocolate;
}

void FracKnapSack(vector<Choco> shop, double taka) {
    sort(shop.begin(), shop.end(), compare);

    cout << "after sorting: " << endl;
    for(Choco x : shop) x.display();

    vector<Choco> sack;

    for(Choco& x : shop) {
        if(taka <= 0) {
            break;
        } else if(taka > x.totalPrice) {
            sack.push_back(x);
            taka -= x.totalPrice;
        } else {
            int a = taka / x.perChocolate;
            sack.push_back({ x.name, a, a * x.perChocolate });
            taka = 0;
        }
    }

    cout << "after shopping: " << endl;
    for(Choco x : sack) x.display();

    int maxx = 0;
    for(Choco x : sack) maxx += x.amount;
    cout << "maximum chocolates: " << maxx << endl;
}

int main() {
    vector<Choco> shop = {
        { "mr.mango", 30, 30 },
        { "toffee", 4, 12 },
        { "Milk candy", 5, 10 },
        { "Kitkat", 10, 40 }
    };

    cout << "before shopping: " << endl;
    for(Choco x : shop) x.display();

    FracKnapSack(shop, 50);
    return 0;
}
