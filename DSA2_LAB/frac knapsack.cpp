#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
    string name;
    double weight, value, unitValue;
    void display() {
        cout << name << "\t| " << weight << "\t| " << value << endl;
    }
    Item(string n, double w, double v)
    : name(n), weight(w), value(v) {
        unitValue = v / w;
    }
};

void FracKnapSack(vector<Item> s, double capacity) {
    sort(s.begin(), s.end(), [](Item n1, Item n2) { return n1.unitValue > n2.unitValue; });
    cout << endl
         << "sorting before robbing::" << endl
         << endl;
    for(Item& x : s) x.display();
    cout << "-----------------------" << endl;
    vector<Item> sack;
    for(Item& x : s) {
        if(capacity <= 0) break;
        if(x.weight < capacity) {
            sack.push_back(x);
            capacity -= x.weight;
            x.weight = 0;
        } else {
            sack.push_back({ x.name, capacity, capacity * x.unitValue });
            x.weight -= capacity;
            capacity = 0;
        }
    }

    double totalProfit = accumulate(sack.begin(), sack.end(), 0.0, [](double sum, const Item& i) { return sum + i.value; });

    cout << endl
         << "shop after rob::" << endl
         << endl;
    for(Item& x : s) x.display();
    cout << "-----------------------" << endl;
    cout << endl
         << "sack after rob::" << endl
         << endl;
    cout << "profit = " << totalProfit << endl;
    for(Item& x : sack) x.display();
}

int main() {
    vector<Item> shop = {
        { "rice", 5, 300 },
        { "saffron", 2, 8000 },
        { "salt", 10, 200 },
        { "sugar", 4, 400 }
    };
    cout << endl
         << "shop before rob::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;
    double capacity = 8;
    FracKnapSack(shop, capacity);
    return 0;
}
