#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
vector<int> adj[MAXN];
int dist[MAXN];
bool vis[MAXN];
int pre[MAXN];
int ans;
int start;

void dfs(int v, int d, int p) {
    if (vis[v]) {
        if (d - dist[v] > 2) ans = p, start = v;
        return;
    }
    vis[v] = true;
    dist[v] = d;
    pre[v] = p;
    for (auto u : adj[v])
        dfs(u, d + 1, v);
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
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        ans = -1;
        dfs(i, 0, -1);
        if (ans != -1) {
            vector<int> sol;
            sol.push_back(start);
            for (int j = ans; j != start; j = pre[j])
                sol.push_back(j);
            sol.push_back(start);
            cout << sol.size() << '\n';
            for (int j = 0; j < sol.size(); j++)
                cout << sol[j] + 1 << " \n"[j + 1 == sol.size()];
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
