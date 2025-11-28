#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    int n;
    vector<int> p, Rank;

    public:
    DisjointSet(int n) : n(n) {
        p    = vector<int>(n);
        Rank = vector<int>(n);
    }
    void make_set(int x) {
        p[x]    = x;
        Rank[x] = 0;
    }
    int Find(int x) {
        // returns the representative of the set containing x
        if(x != p[x])
            p[x] = Find(p[x]);  // path compression
        return p[x];
    }
    void Union(int a, int b) {
        // merge the sets containing a and b
        int x = Find(a);
        int y = Find(b);
        if(x == y) {
            // both have the same representative
            // they are already in the same set
            // no need to union
            return;
        }
        // union by rank
        if(Rank[x] > Rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if(Rank[x] == Rank[y])
                Rank[y]++;
        }
    }
};

class Graph {
    int n;
    vector<vector<int>> edges;

    public:
    Graph(int n) : n(n) {
    }
    void addEdge(int u, int v, int w) {
        edges.push_back({ w, u, v });
    }

    int MST_size() {
        vector<vector<int>> T;
        DisjointSet x(n);
        for(int i = 0; i < n; i++) x.make_set(i);
        sort(edges.begin(), edges.end());
        for(int i = 0; i < edges.size(); i++)
            if(x.Find(edges[i][1]) != x.Find(edges[i][2])) {
                T.push_back({ edges[i][1], edges[i][2], edges[i][0] });
                x.Union(edges[i][1], edges[i][2]);
            }
        return T.size();
    }
};

class Islands {
    public:
    int n;
    vector<vector<int>> links;

    Islands(int sizee) {
        n = sizee;
    }
    void addLink(int u, int v) {
        links.push_back({ u, v });
    }
    bool isConnected() {
        Graph g(n);
        for(vector<int> x : links)
            g.addEdge(x[0], x[1], 0);
        if(n - 1 != g.MST_size())
            return false;
        else
            return true;
    }
};

int main() {
    Islands i(7);
    i.addLink(1, 2);
    i.addLink(1, 3);
    i.addLink(1, 4);
    i.addLink(3, 4);
    i.addLink(5, 6);
    //    i.addLink(4,7);
    //    i.addLink(7,6);
    bool is = i.isConnected();
    if(is)
        cout << "Connected" << endl;
    else
        cout << "Not Connected" << endl;
}
