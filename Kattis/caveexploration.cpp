#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e4 + 1;
enum { UNVISITED = -1,
       VISITED = -2 };

int n, m;
vector<int> adj[MAXN];
int num[MAXN], low[MAXN], par[MAXN];
map<pair<int, int>, bool> bridge;
int dfsnum = 0;
int ans = 0;

void dfs1(int v) {
    num[v] = dfsnum++;
    low[v] = num[v];
    for (auto u : adj[v]) {
        if (num[u] == UNVISITED) {
            par[u] = v;

            dfs1(u);

            if (low[u] > num[v])
                bridge[{v, u}] = true;

            low[v] = min(low[v], low[u]);
        } else if (u != par[v])
            low[v] = min(low[v], num[u]);
    }
}

void dfs2(int v) {
    num[v] = VISITED;
    ans++;
    for (auto u : adj[v]) {
        if (bridge[{v, u}] || bridge[{u, v}]) continue;
        if (num[u] == VISITED) continue;
        dfs2(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(num, UNVISITED, sizeof num);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0);

    memset(num, UNVISITED, sizeof num);

    dfs2(0);

    cout << ans << '\n';
}
