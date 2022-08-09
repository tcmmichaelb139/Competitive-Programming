#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;
enum { UNVISITED = -1,
       VISITED = -2,
       BIPARTITE = -3 };

int n;
vector<int> adj[MAXN];
int bipartite[MAXN];

void dfs(int v, int bi) {
    bipartite[v] = (bi ? BIPARTITE : VISITED);

    for (auto u : adj[v]) {
        if (bipartite[u] != UNVISITED) continue;
        dfs(u, !bi);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        v.push_back({a, b});
    }
    memset(bipartite, UNVISITED, sizeof bipartite);
    dfs(1, 1);
    for (auto i : v) {
        cout << (bipartite[i.first] == BIPARTITE) << '\n';
    }
}
