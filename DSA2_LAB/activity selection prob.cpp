#include <bits/stdc++.h>
using namespace std;

class Activity {
    public:
    int startT;
    int endT;
    Activity(int s, int e)
    : startT(s), endT(e) {
    }
    void display() {
        cout << "[" << startT << "-" << endT << "]" << endl;
    }
};

bool activityCompare(Activity n1, Activity n2) {
    return n1.endT < n2.endT;
}

void activitySelection(vector<Activity> a) {
    sort(a.begin(), a.end(), activityCompare);
    for(Activity& x : a) x.display();
    cout << "-----------------------" << endl;
    vector<Activity> selected = { a.front() };
    for(Activity x : a)
        if(x.startT >= selected.back().endT) selected.push_back(x);
    cout << "selected = " << selected.size() << endl;
    for(Activity& x : selected) x.display();
}

int main() {
    vector<Activity> a = { { 8, 12 }, { 9, 10 }, { 14, 16 }, { 11, 13 }, { 9, 11 }, { 10, 12 } };
    for(Activity& x : a) x.display();
    cout << "-----------------------" << endl;
    activitySelection(a);
    return 0;
}
