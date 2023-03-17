#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int minWeight = INT_MAX;
class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
};

vector<Edge> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> mst;
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.w < b.w; });
    DisjointSet ds(n);
    for (auto& e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            mst.push_back(e);
            ds.unite(e.u, e.v);
        }
    }
    return mst;
}
int countMSTs(vector<Edge>& edges, int n) {
    for (auto& e : edges) {
        minWeight = min(minWeight, e.w);
    }
    int count = 0;
    for (auto& e : edges) {
        if (e.w == minWeight) {
            vector<Edge> mst = kruskal(edges, n);
            if (mst.size() == n - 1) {
                set<vector<int>> trees;
                for (auto& e : mst) {
                    trees.insert({e.u, e.v});
                }
                count += trees.size();
            }
        }
    }
    return count;
}
int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter the source, destination, and weight: " << i+1 << ": ";
        cin >> u >> v >> w;
        edges.push_back(Edge(u - 1, v - 1, w));
    }
    int count = countMSTs(edges, n);
    cout << "The minimum spanning trees is: " << count << endl;
}
