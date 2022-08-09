#include "bits/stdc++.h"
using namespace std;

const int MAXN = 5e5 + 1;
enum { UNVISITED = 0,
       VISITED = -1,
       BIPARTITE = -2 };

int n, m;
vector<int> adj[MAXN];
int bipartite[MAXN];
set<int> s;

void dfs(int v) {
    s.insert(v);
    bipartite[v] = (bipartite[v] == UNVISITED ? VISITED : bipartite[v]);
    for (auto u : adj[v]) {
        s.insert(u);
        bipartite[u] = (bipartite[u] == UNVISITED ? VISITED : bipartite[u]);
        for (auto k : adj[u]) {
            if (k == v) continue;
            if (bipartite[k] == BIPARTITE) continue;
            bipartite[k] = BIPARTITE;
            dfs(k);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool full_bipartite = false;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (bipartite[i] != UNVISITED) continue;
        dfs(i);

        bool full = true;
        for (auto j : s)
            if (bipartite[j] != BIPARTITE)
                full = false;
        s.clear();

        if (full)
            full_bipartite = true;

        ans++;
    }
    if (full_bipartite) ans--;
    cout << ans << '\n';
}
