#include "bits/stdc++.h"
using namespace std;

int n, m;

vector<long long> dijkstra(vector<vector<pair<long long, long long>>> adj, int start) {
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        q;
    q.push({0, start});
    vector<bool> vis(n, false);
    vector<long long> dist(n, 0);
    while (!q.empty()) {
        pair<long long, long long> k = q.top();
        q.pop();

        if (vis[k.second]) continue;
        vis[k.second] = true;
        dist[k.second] = k.first;

        for (auto &[u, w] : adj[k.second]) {
            if (vis[u]) continue;
            q.push({k.first + w, u});
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n);
    vector<vector<pair<long long, long long>>> adj_rev(n);
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj_rev[b].push_back({a, c});
    }
    int s, t;
    cin >> s >> t;

    vector<long long> dist = dijkstra(adj, s);
    vector<long long> dist_rev = dijkstra(adj_rev, t);

    vector<int> ans;
    queue<long long> q;
    vector<bool> in(n, false);

    q.push(s);
    while (!q.empty()) {
        long long v = q.front();
        q.pop();
        in[v] = false;

        if (q.empty()) ans.push_back(v);
        for (auto &[u, w] : adj[v]) {
            if (in[u]) continue;
            if (dist[t] == dist[v] + w + dist_rev[u]) {
                in[u] = true;
                q.push(u);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
}
