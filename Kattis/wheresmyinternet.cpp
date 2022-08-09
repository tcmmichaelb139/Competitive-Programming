#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v])
        if (!vis[u])
            dfs(u);
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

    dfs(1);

    bool connected = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            cout << i << '\n';
            connected = false;
        }

    if (connected)
        cout << "Connected\n";
}
