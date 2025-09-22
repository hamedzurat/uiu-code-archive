#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
    double size, total, per;
    string name;

    Item(string n, double s, double t)
    : name(n), size(s), total(t), per(t / s) {};
    void display() {
        cout << name << "\t| " << size << "L\t| " << total << "g" << endl;
    }
};

void FracKnapSack(vector<Item>& shop, double cap) {
    sort(shop.begin(), shop.end(), [](Item i1, Item i2) { return i1.per < i2.per; });

    cout << endl
         << "shop after sort::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;

    vector<Item> sack;

    for(Item& x : shop) {
        if(cap <= 0)
            break;
        else if(x.size < cap) {
            sack.push_back(x);
            cap -= x.size;
            x.size = 0;
        } else {
            sack.push_back({ x.name, cap, cap * x.per });
            x.size -= cap;
            cap = 0;
        }
    }

    cout << endl
         << "shop after rob::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;

    double T = 0;
    for(Item& i : sack) T += i.total;

    cout << "\ntotal: " << T << endl;
    cout << endl
         << "sack after rob::" << endl
         << endl;
    for(Item& x : sack) x.display();
    cout << "-----------------------" << endl;
}

int main() {
    vector<Item> shop = {
        { "Galxose-D", 3, 75 },
        { "GlucoMax", 4, 80 },
        { "Sting....", 5, 150 }
    };

    cout << endl
         << "shop before selection::" << endl
         << endl;
    for(Item& x : shop) x.display();
    cout << "-----------------------" << endl;

    FracKnapSack(shop, 6);
    return 0;
}

