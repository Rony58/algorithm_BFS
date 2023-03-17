#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, w;
    Edge(int uu, int vv, int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};
bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}
class DisjointSet {
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};
int countMSTs(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet dsu(n);
    int totalWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            totalWeight += w;
        }
    }
    vector<int> size(n, 0);
    for (int i = 0; i < n; i++) {
        size[dsu.find(i)]++;
    }
    int numMSTs = 1;
    for (int i = 0; i < n; i++) {
        if (size[i] > 1) {
            numMSTs *= size[i];
        }
    }
    return numMSTs;
}
int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges;
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cout << "Enter edge " << i + 1 << " (u v w): ";
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    int numMSTs = countMSTs(edges, numNodes);
    cout << "Number of distinct minimum spanning trees: " << numMSTs << endl;
    return 0;
}
