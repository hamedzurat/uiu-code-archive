#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> _;
    _.push(start);
    visited[start] = true;

    while(!_.empty()) {
        int node = _.front();
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

    cout << "BFS starting from node 0:\n";
    bfs(0, graph, visited);
    cout << endl;

    return 0;
}
