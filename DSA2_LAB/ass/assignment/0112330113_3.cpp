#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
    string name;
    double weight, profit, unitProfit;

    Item(string n, double w, double wholesale, double perKg) {
        name       = n;
        weight     = w;
        profit     = (perKg * w) - wholesale;
        unitProfit = profit / w;
    }

    void display() {
        cout << name << "\t| " << weight << "kg\t| " << profit << endl;
    }
};

bool Compare(Item a, Item b) {
    return a.unitProfit > b.unitProfit;
}

void FracKnapSack(vector<Item> products, double capacity) {
    sort(products.begin(), products.end(), Compare);

    cout << endl
         << "products after sorting::" << endl
         << endl;
    for(Item& x : products) x.display();
    cout << "-----------------------" << endl;

    vector<Item> sack;
    for(Item& x : products) {
        if(capacity <= 0) break;
        if(x.weight <= capacity) {
            sack.push_back(x);
            capacity -= x.weight;
            x.weight = 0;
        } else {
            sack.push_back({ x.name, capacity, 0, x.unitProfit + 0 });
            x.weight -= capacity;
            capacity = 0;
        }
    }

    double totalProfit = 0;
    for(Item& i : sack) totalProfit += i.profit;

    cout << endl
         << "products after selection::" << endl
         << endl;
    for(Item& x : products) x.display();
    cout << "-----------------------" << endl;

    cout << endl
         << "sack after selection::" << endl
         << endl;
    cout << "Maximum Profit = " << totalProfit << endl;
    for(Item& x : sack) x.display();
}

int main() {
    vector<Item> shop = {
        { "Rice", 100, 4000, 55 },
        { "Sugar", 200, 9000, 62 },
        { "Wheat", 350, 7000, 30 },
        { "Onion", 250, 12000, 80 }
    };

    cout << endl
         << "shop before selection::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;

    FracKnapSack(shop, 600);
    return 0;
}
