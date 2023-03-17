#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
void topological_Sort(vector<vector<int>> &g, vector<int> &in_degree) {
    int N = g.size();
    vector<int> sortedOrder;
    queue<int> s;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            s.push(i);
        }
    }
    while (!s.empty()) {
        int current = s.front();
        s.pop();
        sortedOrder.push_back(current);

        for (auto neighbor : g[current]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                s.push(neighbor);
            }
        }
    }
    if (sortedOrder.size() != N) {
        cout << "There is a cycle." << endl;
    } else {
        cout << "Topological order: ";
        for (auto v : sortedOrder) {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main() {
    int N;
    cout << "Enter the number of vertices: ";
    cin >> N;
    vector<vector<int>> g(N);
    vector<int> in_degree(N);
    cout << "Enter the edges:" << endl;
    int v, w;
    while (cin >> v >> w) {
        g[v].push_back(w);
        in_degree[w]++;
    }
    topological_Sort(g, in_degree);
}
