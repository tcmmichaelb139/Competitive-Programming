#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<long long> ans;
    vector<int> vis(n + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    q.push({0, 1});

    while (!q.empty()) {
        pair<long long, int> v = q.top();
        q.pop();

        if (v.second == n) {
            ans.push_back(v.first);
            if (ans.size() == k) break;
        }

        if (vis[v.second]++ > k) continue;

        for (auto u : adj[v.second]) {
            if (vis[u.first] > k) continue;
            q.push({v.first + u.second, u.first});
        }
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << " \n"[i + 1 == k];
}
