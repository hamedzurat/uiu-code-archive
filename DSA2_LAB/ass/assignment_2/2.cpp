#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    char source;
    char destination;
    int weight;
};

class Graph {
    public:
    int vertices;
    vector<Edge> edges;
    map<char, int> charToIndex;
    map<int, char> indexToChar;

    Graph(vector<char> islands) {
        vertices = islands.size();
        for(int i = 0; i < islands.size(); i++) {
            charToIndex[islands[i]] = i;
            indexToChar[i]          = islands[i];
        }
    }

    void addEdge(char source, char destination, int weight) {
        edges.push_back({ source, destination, weight });
    }

    // Prim's Algorithm for MST
    int primsMST() {
        int n = vertices;

        // Build adjacency list
        vector<pair<int, int>> adj[n];  // {neighbor_index, weight}

        for(auto& e : edges) {
            int u = charToIndex[e.source];
            int v = charToIndex[e.destination];
            adj[u].push_back({ v, e.weight });
            adj[v].push_back({ u, e.weight });
        }

        // Priority queue: {weight, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> inMST(n, false);
        vector<int> key(n, INT_MAX);
        vector<int> parent(n, -1);

        int totalCost = 0;

        // Start from vertex 0
        pq.push({ 0, 0 });
        key[0] = 0;

        while(!pq.empty()) {
            int weight = pq.top().first;
            int u      = pq.top().second;
            pq.pop();

            if(inMST[u]) continue;

            inMST[u] = true;
            totalCost += weight;

            // Check all neighbors
            for(auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if(!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({ w, v });
                    parent[v] = u;
                }
            }
        }

        // Print MST edges
        cout << "\nThe following bridges should be built:\n";
        vector<pair<int, pair<char, char>>> mstEdges;

        for(int i = 1; i < n; i++) {
            char from = indexToChar[parent[i]];
            char to   = indexToChar[i];
            mstEdges.push_back({ key[i], { from, to } });
        }

        // Sort by weight for output
        sort(mstEdges.begin(), mstEdges.end());

        for(auto& edge : mstEdges) {
            cout << edge.second.first << "->" << edge.second.second
                 << " : " << edge.first << endl;
        }

        return totalCost;
    }
};

int main() {
    // Define islands
    vector<char> islands = { 'A', 'B', 'C', 'D', 'E', 'F' };
    Graph graph(islands);

    // Add edges (bridges with costs)
    // Creating a graph similar to the expected output
    graph.addEdge('A', 'B', 3);
    graph.addEdge('A', 'C', 6);
    graph.addEdge('B', 'C', 9);
    graph.addEdge('B', 'E', 5);
    graph.addEdge('C', 'D', 2);
    graph.addEdge('C', 'E', 8);
    graph.addEdge('D', 'E', 1);
    graph.addEdge('D', 'F', 7);
    graph.addEdge('E', 'F', 4);

    cout << "======================================\n";
    cout << "MINIMUM COST TO CONNECT ISLANDS\n";
    cout << "======================================\n";

    int minCost = graph.primsMST();

    cout << "\nMinimum cost to connect islands: " << minCost << endl;

    return 0;
}

/*
PRIM'S ALGORITHM FOR MST:
=========================

CONCEPT:
--------
Find minimum cost to connect all islands (vertices) using bridges (edges)
without forming cycles. This creates a Minimum Spanning Tree (MST).

ALGORITHM STEPS:
----------------
1. Start with any vertex (say vertex 0)
2. Maintain:
   - inMST[]: tracks vertices in MST
   - key[]: minimum weight to connect each vertex
   - parent[]: parent in MST tree
   - Priority Queue: {weight, vertex} pairs

3. While PQ not empty:
   - Extract vertex with minimum weight
   - Mark as in MST
   - For each neighbor:
     * If not in MST and edge weight < key[neighbor]
     * Update key and parent
     * Push to PQ

4. Sum all key values = total MST cost

TIME COMPLEXITY: O(E log V)
- E edges, V vertices
- Each edge processed once
- PQ operations are O(log V)

SPACE COMPLEXITY: O(V + E)
- Adjacency list: O(V + E)
- Arrays and PQ: O(V)

WHY PRIM'S WORKS:
-----------------
Greedy choice: Always pick the minimum weight edge that connects
a vertex outside MST to a vertex inside MST. This guarantees
minimum total cost.

OUTPUT FORMAT:
--------------
Lists edges in order of weight (smallest to largest)
Shows: Island1->Island2 : Cost
*/
