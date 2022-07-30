#include "bits/stdc++.h"
using namespace std;

pair<int, int> bfs(int n, vector<vector<int>> adj, int start) {
    vector<bool> vis(n, false);
    pair<int, int> ans = {0, 0};
    queue<pair<int, int>> q;
    q.push({0, start});
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        if (vis[v.second]) continue;
        if (ans.first < v.first) ans = v;
        vis[v.second] = true;
        for (auto u : adj[v.second]) {
            q.push({v.first + 1, u});
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << bfs(n, adj, bfs(n, adj, 0).second).first << '\n';
}
