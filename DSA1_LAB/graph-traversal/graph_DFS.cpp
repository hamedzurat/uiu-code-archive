#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> _;
    _.push(start);
    visited[start] = true;

    while(!_.empty()) {
        int node = _.top();
        _.pop();

        cout << node << " ";

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                _.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        { 1, 2 },
        { 0, 3, 4 },
        { 0 },
        { 1 },
        { 1 }
    };
    vector<bool> visited(graph.size(), false);

    cout << "DFS (iterative) starting from node 0:\n";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}
