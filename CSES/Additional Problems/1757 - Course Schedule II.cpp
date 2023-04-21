#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
vector<int> adj[MAXN];
int deg[MAXN];
bool globVis[MAXN];

void dfs(int v) {
    for (auto u : adj[v]) {
        deg[u]++;
        if (globVis[u]) continue;
        globVis[u] = true;
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    vector<int> ans;
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        dfs(i);

        priority_queue<int> q;

        deque<int> cur;

        q.push(i);

        while (!q.empty()) {
            int v = q.top();
            q.pop();

            if (vis[v]) continue;
            vis[v] = true;

            cur.push_front(v);

            for (auto u : adj[v]) {
                if (--deg[u]) continue;
                q.push(u);
            }
        }

        while (!cur.empty())
            ans.push_back(cur.front()), cur.pop_front();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i + 1 == n];
}
