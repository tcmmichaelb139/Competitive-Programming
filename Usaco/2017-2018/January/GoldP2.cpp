#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, k;
vector<int> adj[MAXN];

vector<int> bfs(vector<int> start) {
    vector<int> dist(n, 1e9);
    vector<bool> vis(n, false);

    queue<int> q;
    for (auto i : start)
        q.push(i), dist[i] = 0, vis[i] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = true;

            q.push(u);
            dist[u] = min(dist[u], dist[v] + 1);
        }
    }

    return dist;
}

int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    k--;
    vector<int> edges(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a]++, edges[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> exit;
    for (int i = 0; i < n; i++)
        if (edges[i] == 1)
            exit.push_back(i);

    vector<int> farmer = bfs(exit);
    vector<int> bessie = bfs({k});

    int ans = 0;

    vector<bool> vis(n, false);
    queue<int> q;
    q.push(k);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (farmer[v] <= bessie[v]) {
            ans++;
            continue;
        }

        for (auto u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = true;

            q.push(u);
        }
    }

    cout << ans << '\n';
}
