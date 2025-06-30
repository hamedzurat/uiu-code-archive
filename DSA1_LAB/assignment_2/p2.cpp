#include <bits/stdc++.h>
using namespace std;

int n;
int min_so_far;
vector<vector<int>> cost;
vector<bool> visited;

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << cost[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void min_cost_calc(int now, int deepth, int cost_so_far) {
    if(deepth == n) {
        if(cost[now][0] != 0) {
            int total = cost_so_far + cost[now][0];
            if(total < min_so_far) min_so_far = total;
        }
        return;
    }

    if(cost_so_far >= min_so_far) return;

    for(int next = 0; next < n; next++) {
        if(!visited[next] && cost[now][next] != 0) {
            visited[next] = true;
            min_cost_calc(next, deepth + 1, cost_so_far + cost[now][next]);
            visited[next] = false;
        }
    }
}

int main() {
    n          = 5;
    min_so_far = 999999999;
    cost.resize(n, vector<int>(n));
    visited.resize(n, false);

    cost = {
        { 0, 14, 4, 10, 20 },
        { 14, 0, 7, 8, 7 },
        { 4, 5, 0, 7, 16 },
        { 11, 7, 9, 0, 2 },
        { 18, 7, 17, 4, 0 }
    };

    cout << "input 1:" << endl;
    print();
    visited[0] = true;
    min_cost_calc(0, 1, 0);
    cout << "Minimum cost: " << min_so_far << endl
         << endl;

    //
    //
    //

    n          = 5;
    min_so_far = 999999999;
    cost.resize(n, vector<int>(n));
    visited.resize(n, false);

    cost = {
        { 9, 9, 2, 9, 5 },
        { 6, 3, 5, 1, 5 },
        { 1, 8, 3, 3, 3 },
        { 6, 0, 9, 6, 8 },
        { 6, 6, 9, 4, 8 }
    };

    cout << "input 2:" << endl;
    print();
    visited[0] = true;
    min_cost_calc(0, 1, 0);
    cout << "Minimum cost: " << min_so_far << endl
         << endl;

    return 0;
}
