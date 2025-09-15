#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
    string name;
    double volume, glucose, unitGlucose;
    void display() {
        cout << name << "\t| " << volume << "L\t| " << glucose << "g" << endl;
    }
    Item(string n, double v, double g)
    : name(n), volume(v), glucose(g) {
        unitGlucose = g / v;
    }
};

bool Compare(Item a, Item b) {
    return a.unitGlucose < b.unitGlucose;
}


void FracKnapSack(vector<Item> drinks, double capacity) {
    sort(drinks.begin(), drinks.end(), Compare);

    cout << endl
         << "sorting before selection::" << endl
         << endl;
    for(Item& x : drinks) x.display();
    cout << "-----------------------" << endl;

    vector<Item> sack;
    for(Item& x : drinks) {
        if(capacity <= 0) break;
        if(x.volume <= capacity) {
            sack.push_back(x);
            capacity -= x.volume;
            x.volume = 0;
        } else {
            sack.push_back({ x.name, capacity, capacity * x.unitGlucose });
            x.volume -= capacity;
            capacity = 0;
        }
    }

    double totalGlucose = 0;
    for(Item& i : sack) totalGlucose += i.glucose;

    cout << endl
         << "drinks after selection::" << endl
         << endl;
    for(Item& x : drinks) x.display();
    cout << "-----------------------" << endl;

    cout << endl
         << "sack after selection::" << endl
         << endl;
    cout << "Minimum Glucose = " << totalGlucose << " g" << endl;
    for(Item& x : sack) x.display();
}

int main() {
    vector<Item> shop = {
        { "Galxose-D", 3, 75 },
        { "GlucoMax", 4, 80 },
        { "Sting", 5, 150 }
    };

    cout << endl
         << "shop before selection::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;

    FracKnapSack(shop, 6);
    return 0;
}
