#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e4 + 1;

int n, m;
int val[MAXN];
vector<int> adj[MAXN];
int par[MAXN];
int dist[MAXN];

void dfs(int v) {
    for (auto u : adj[v]) {
        dist[u] = max(dist[u], dist[v] + val[u]);
        if (--par[u] == 0)
            dfs(u);
    }
}

int main() {
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        par[b]++;
    }

    for (int i = 1; i <= n; i++)
        par[i]++, adj[0].push_back(i);

    dfs(0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);

    cout << ans << '\n';
}
