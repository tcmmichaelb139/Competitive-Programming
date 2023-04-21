/*
ID: tcmmich1
TASK: butter
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, m;
    cin >> n >> p >> m;
    vector<int> num(p + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num[a]++;
    }

    vector<pair<int, int>> adj[p + 1];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ans = 1e9;
    for (int i = 1; i <= p; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});

        vector<int> vis(p + 1, false);
        int cur = 0;

        while (!q.empty()) {
            pair<int, int> v = q.top();
            q.pop();

            if (vis[v.second]) continue;
            vis[v.second] = true;

            cur += v.first * num[v.second];

            for (auto u : adj[v.second]) {
                q.push({u.second + v.first, u.first});
            }
        }

        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
