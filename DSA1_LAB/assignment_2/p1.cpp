#include <bits/stdc++.h>
using namespace std;

int MAX = 100;

void add(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void print(vector<vector<int>>& graph) {
    for(int i = 0; i < graph.size(); i++) {
        if(!graph[i].empty()) {
            cout << i << ": ";
            for(int n : graph[i]) cout << n << "\t";
            cout << endl;
        }
    }
    cout << endl;
}

int min_length(vector<vector<int>>& graph, int from, int to) {
    if(from == to) return 0;

    vector<int> distance(MAX, -1);
    queue<int> q;

    distance[from] = 0;
    q.push(from);

    while(!q.empty()) {
        int c = q.front();
        q.pop();

        for(int n : graph[c]) {
            if(distance[n] == -1) {
                distance[n] = distance[c] + 1;
                q.push(n);

                if(n == to) return distance[n];
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> graph(MAX);

    add(graph, 0, 1);
    add(graph, 0, 7);
    add(graph, 1, 7);
    add(graph, 1, 2);
    add(graph, 2, 3);
    add(graph, 2, 5);
    add(graph, 2, 8);
    add(graph, 3, 4);
    add(graph, 3, 5);
    add(graph, 4, 5);
    add(graph, 5, 6);
    add(graph, 6, 7);
    add(graph, 7, 8);

    print(graph);

    cout << "Min number of edges between (0, 5): " << min_length(graph, 0, 5) << endl;
    cout << "Min number of edges between (3, 8): " << min_length(graph, 3, 8) << endl;
    cout << "Min number of edges between (2, 6): " << min_length(graph, 2, 6) << endl;

    return 0;
}