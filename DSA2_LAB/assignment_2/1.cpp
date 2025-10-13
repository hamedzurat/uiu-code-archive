#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int vertices;
    vector<vector<int>> adjMat;

    Graph(int v) {
        vertices = v;
        adjMat.resize(v, vector<int>(v, INT_MAX));
        // Distance from vertex to itself is 0
        for(int i = 0; i < v; i++) {
            adjMat[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int w) {
        adjMat[u][v] = w;
        adjMat[v][u] = w;
    }

    // Dijkstra's algorithm to find shortest path
    pair<int, vector<int>> dijkstra(int src, int dest) {
        vector<int> dist(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src });

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            for(int v = 0; v < vertices; v++) {
                if(adjMat[u][v] != INT_MAX && !visited[v]) {
                    if(dist[u] + adjMat[u][v] < dist[v]) {
                        dist[v]   = dist[u] + adjMat[u][v];
                        parent[v] = u;
                        pq.push({ dist[v], v });
                    }
                }
            }
        }

        // Reconstruct path
        vector<int> path;
        if(dist[dest] == INT_MAX) {
            return { INT_MAX, path };  // No path exists
        }

        int curr = dest;
        while(curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        return { dist[dest], path };
    }

    // Find direct path from S to D
    void findPath(int S, int D) {
        auto result      = dijkstra(S, D);
        int time         = result.first;
        vector<int> path = result.second;

        cout << "\nDirect Path (Restaurant -> Delivery):\n";
        cout << "Time: " << time << " minutes\n";
        cout << "Path: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i];
            if(i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    // Find path from S to G to D
    void findPath(int S, int G, int D) {
        auto result1      = dijkstra(S, G);
        int time1         = result1.first;
        vector<int> path1 = result1.second;

        auto result2      = dijkstra(G, D);
        int time2         = result2.first;
        vector<int> path2 = result2.second;

        int totalTime = time1 + time2;

        cout << "\nPath with Gas Station (Restaurant -> Gas Station -> Delivery):\n";
        cout << "Time (Restaurant -> Gas Station): " << time1 << " minutes\n";
        cout << "Path: ";
        for(int i = 0; i < path1.size(); i++) {
            cout << path1[i];
            if(i < path1.size() - 1) cout << " -> ";
        }
        cout << endl;

        cout << "Time (Gas Station -> Delivery): " << time2 << " minutes\n";
        cout << "Path: ";
        for(int i = 0; i < path2.size(); i++) {
            cout << path2[i];
            if(i < path2.size() - 1) cout << " -> ";
        }
        cout << endl;

        cout << "Total Time: " << totalTime << " minutes\n";
    }
};

int main() {
    // Example: 6 streets (0 to 5)
    Graph graph(6);

    // Add edges (street connections with time)
    graph.addEdge(0, 1, 5);  // Restaurant at 0
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 3);
    graph.addEdge(4, 5, 5);

    int S = 0;  // Restaurant
    int G = 2;  // Gas Station
    int D = 5;  // Delivery Location

    cout << "======================================\n";
    cout << "DELIVERY ROUTE OPTIMIZATION\n";
    cout << "======================================\n";
    cout << "Restaurant: Street " << S << endl;
    cout << "Gas Station: Street " << G << endl;
    cout << "Delivery Location: Street " << D << endl;

    // Direct path
    auto directResult = graph.dijkstra(S, D);
    int directTime    = directResult.first;

    // Path via gas station
    auto toGas     = graph.dijkstra(S, G);
    auto fromGas   = graph.dijkstra(G, D);
    int viaGasTime = toGas.first + fromGas.first;

    graph.findPath(S, D);
    graph.findPath(S, G, D);

    cout << "\n======================================\n";
    cout << "TIME ANALYSIS:\n";
    cout << "======================================\n";
    cout << "Direct time: " << directTime << " minutes\n";
    cout << "Time via gas station: " << viaGasTime << " minutes\n";
    cout << "Time saved if fuel was available: " << (viaGasTime - directTime) << " minutes\n";

    return 0;
}

/*
ALGORITHM EXPLANATION:
======================
1. Use adjacency matrix to store graph
2. Dijkstra's algorithm finds shortest path between two vertices
3. Compare direct path (S->D) vs path via gas station (S->G->D)
4. Calculate time saved

KEY POINTS:
- adjMat[u][v] stores time to travel from u to v
- Dijkstra uses priority queue (min heap)
- Parent array helps reconstruct the path
- Time complexity: O(V^2 log V) with priority queue
*/
