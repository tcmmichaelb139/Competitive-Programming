#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1000;
enum { UNVISITED = -1 };

int n, m;

vector<int> adj[MAXN];
int tin[MAXN], low[MAXN], par[MAXN];
int num = 0;
bool bridge;

void dfs(int v) {
    tin[v] = num++;
    low[v] = tin[v];
    for (auto u : adj[v]) {
        if (tin[u] == UNVISITED) {
            par[u] = v;

            dfs(u);

            if (low[u] > tin[v])
                bridge = true;
            low[v] = min(low[v], low[u]);
        } else if (u != par[v])
            low[v] = min(low[v], tin[u]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        bridge = false;
        memset(tin, UNVISITED, sizeof tin);
        memset(par, UNVISITED, sizeof par);
        for (int i = 0; i < MAXN; i++)
            adj[i].clear(), low[i] = 1e9;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0);

        for (int i = 0; i < n; i++)
            if (tin[i] == UNVISITED)
                bridge = true;

        cout << (bridge ? "Yes" : "No") << '\n';
    }
}
