#include "bits/stdc++.h"
using namespace std;

const int MAXN = 501;

int n, m, x;

struct node {
    int v, l, c;
    bool operator<(const node& rhs) const { return l + x / c > rhs.l + x / rhs.c; }
};

int main() {
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    vector<vector<node>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }

    vector<bool> vis(n + 1, false);
    priority_queue<node> q;
    q.push({1, 0, (int)1e9});

    while (!q.empty()) {
        node k = q.top();
        q.pop();
        if (vis[k.v]) continue;
        vis[k.v] = true;

        if (k.v == n) {
            cout << k.l + x / k.c << '\n';
            return 0;
        }

        for (auto u : adj[k.v]) {
            q.push({u.v, k.l + u.l, min(k.c, u.c)});
        }
    }
}
