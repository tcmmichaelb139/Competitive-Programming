#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 1;
enum { UNVISITED = -1,
       VISITED = -2 };

int n, m;
vector<int> adj[MAXN];
int vis[MAXN];
int par[MAXN];
vector<int> ans;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        ans.push_back(k);
        for (auto u : adj[k]) {
            if (vis[u] == VISITED) continue;
            if (--par[u] > 0) continue;
            vis[u] = VISITED;
            q.push(u);
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
        a--, b--;
        adj[a].push_back(b);
        par[b]++;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] == VISITED) continue;
        if (par[i] > 0) continue;
        bfs(i);
    }
    if (ans.size() == n) {
        for (auto i : ans)
            cout << i + 1 << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
