#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n;
vector<int> adj[MAXN];
int f[MAXN], h[MAXN], ans[MAXN];

void dfs1(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p) continue;

        dfs1(u, v);
        if (f[u] + 1 > f[v]) {
            h[v] = f[v];
            f[v] = max(f[v], f[u] + 1);
        } else if (f[u] + 1 > h[v]) {
            h[v] = f[u] + 1;
        }
    }
}

void dfs2(int v, int p, int g) {
    ans[v] = max(g, f[v]);
    for (auto u : adj[v]) {
        if (u == p) continue;

        if (f[v] == f[u] + 1)
            dfs2(u, v, max(g, h[v]) + 1);
        else
            dfs2(u, v, ans[v] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
