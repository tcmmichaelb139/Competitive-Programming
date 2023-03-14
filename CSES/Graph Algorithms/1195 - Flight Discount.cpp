#include "bits/stdc++.h"
using namespace std;

struct node {
    int v;
    long long dist;
    bool done;

    bool operator<(const node& rhs) const {
        return dist > rhs.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));

    priority_queue<node> q;
    q.push({1, 0, 0});

    while (!q.empty()) {
        node v = q.top();
        q.pop();

        if (v.v == n) {
            cout << v.dist << '\n';
            break;
        }

        if (vis[v.v][v.done]) continue;
        vis[v.v][v.done] = true;

        for (auto u : adj[v.v]) {
            q.push({u.first, v.dist + u.second, v.done});
            if (!v.done)
                q.push({u.first, v.dist + u.second / 2, 1});
        }
    }
}
