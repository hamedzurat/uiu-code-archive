#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name;
    int w, v;
};

void Knapsack01(vector<Item> items, int W) {
    int n = items.size();
    vector<vector<int>> P(n + 1, vector<int>(W + 1, 0));

    // fill DP table
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(items[i - 1].w > j)
                P[i][j] = P[i - 1][j];
            else
                P[i][j] = max(P[i - 1][j],
                items[i - 1].v + P[i - 1][j - items[i - 1].w]);
        }
    }

    cout << "Maximum profit: " << P[n][W] << "\nSelected items:\n";

    // backtrack
    int j = W;
    for(int i = n; i > 0; --i) {
        if(P[i][j] != P[i - 1][j]) {
            cout << items[i - 1].name << " (w:" << items[i - 1].w
                 << ", v:" << items[i - 1].v << ")\n";
            j -= items[i - 1].w;
        }
    }
}

int main() {
    vector<Item> items = {
        { "Rice", 2, 12 },
        { "Sugar", 1, 10 },
        { "salt", 3, 20 },
        { "lentil", 2, 15 }
    };
    Knapsack01(items, 5);
}
