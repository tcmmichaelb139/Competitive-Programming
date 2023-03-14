#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e4 + 1;

int n, m, t;
vector<pair<long long, long long>> adj[MAXN];

vector<long long> dijkstra() {
    struct node {
        long long v;
        long long dist;
        bool operator<(const node& rhs) const {
            return dist > rhs.dist;
        }
    };

    vector<bool> vis(n + 1, false);
    vector<long long> dist(n + 1);
    priority_queue<node> q;
    q.push({1, 0});

    while (!q.empty()) {
        node v = q.top();
        q.pop();

        if (vis[v.v]) continue;
        vis[v.v] = true;

        dist[v.v] = v.dist;

        for (auto u : adj[v.v])
            q.push({u.first, u.second + v.dist});
    }

    return dist;
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    vector<long long> num(n + 1);
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++)
        sort(begin(adj[i]), end(adj[i]));

    vector<long long> dist = dijkstra();

    vector<pair<long long, long long>> distSorted;
    for (int i = 1; i <= n; i++)
        distSorted.push_back({dist[i], i});

    sort(rbegin(distSorted), rend(distSorted));

    for (auto [d, v] : distSorted) {
        if (v == 1) continue;
        long long mn = 1e9;
        for (auto u : adj[v])
            if (d == dist[u.first] + u.second)
                mn = min(mn, u.first);
        num[mn] += num[v];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, (dist[i] - t) * num[i]);
    cout << ans << '\n';
}
