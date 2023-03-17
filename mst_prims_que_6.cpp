#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100005;

int n, m, cnt, ans;
vector<pair<int, int>> G[MAXN];
int vis[MAXN], d[MAXN], num[MAXN];
void prim(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    d[s] = 0;
    num[s] = 1;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cnt += num[u] > 1;
        ans *= num[u];
        for (auto& e : G[u]) {
            int v = e.first, w = e.second;
            if (!vis[v] && d[v] > w) {
                d[v] = w;
                num[v] = 1;
                q.push({d[v], v});
            } else if (!vis[v] && d[v] == w) {
                num[v]++;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int s;
    cin >> s;
    cout << "Edges and their weights:\n";
    for (int u = 1; u <= n; u++) {
        for (auto& e : G[u]) {
            int v = e.first, w = e.second;
            if (u < v) {
                cout << u << " " << v << " " << w << "\n";
            }
        }
    }
    ans = 1;
    prim(s);
    cout << "Number of distinct minimum spanning trees: " << cnt + (ans == 1 ? 1 : ans) << "\n";
}

