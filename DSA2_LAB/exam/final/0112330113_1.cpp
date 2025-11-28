#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> w;
    bool directed;
    vector<int> q, d, p;

    public:
    Graph(int n, bool dir) : n(n), directed(dir) {
        w = vector<vector<int>>(n, vector<int>(n, 0));
    }
    void addEdge(int u, int v, int w1) {
        w[u][v] = w1;
        if(!directed) w[v][u] = w1;
    }
    bool isEdge(int u, int v) {
        if(w[u][v] != 0) return true;
        return false;
    }
    int ExtractMin() {
        int m   = INT_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++)
            if(q[i] == 1 && d[i] < m) {
                m   = d[i];
                idx = i;
            }
        return idx;
    }
    void Dijkstra(int src) {
        p      = vector<int>(n, -1);
        d      = vector<int>(n, INT_MAX);
        q      = vector<int>(n, 1);
        d[src] = 0;

        for(int i = 1; i <= n; i++) {
            int u = ExtractMin();
            cout << u << endl;
            q[u] = 0;
            for(int v = 0; v < n; v++) {
                if(isEdge(u, v)) {
                    if(d[u] + w[u][v] < d[v]) {
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
        }
    }
    void printPath(int d) {
        if(d == -1) return;
        printPath(p[d]);
        cout << d << "-->";
    }
    int findPath(int s, int dest) {
        Dijkstra(s);
        return d[dest];
    }
};

class CityNetwork {
    int n;
    vector<vector<int>> roads;
    Graph g = Graph(6, true);

    public:
    CityNetwork(int sizee) {
        //        g= Graph(sizee, false);
    }

    void addRoad(int u, int v, int travel_time, int isBlocked, int hasToll) {
        roads.push_back({ u, v, travel_time, isBlocked, hasToll });
    }

    void dijkstra(int src) {
        for(vector<int> x : roads) {
            if(x[3] == 0 && x[4] == 0) {
                g.addEdge(x[0], x[1], x[2]);
                cout << x[0] << "," << x[1] << "," << x[2] << ",";
            }
            cout << endl;
        }
    }
    void findPath(int src, int dest) {
        dijkstra(src);
        cout << "cost: " << g.findPath(src, dest) << endl;
        cout << "distance from " << src << " to " << dest << endl;
        g.printPath(dest);
    }
};

int main() {
    CityNetwork city(6);
    city.addRoad(0, 1, 4, 0, 0);
    city.addRoad(0, 2, 2, 0, 1);
    city.addRoad(1, 2, 1, 1, 0);
    city.addRoad(1, 3, 5, 0, 0);
    city.addRoad(2, 3, 8, 1, 0);
    city.addRoad(2, 4, 10, 0, 1);
    city.addRoad(3, 4, 2, 0, 0);
    city.addRoad(4, 5, 3, 0, 0);
    city.addRoad(3, 5, 6, 0, 0);
    city.findPath(0, 5);
}
