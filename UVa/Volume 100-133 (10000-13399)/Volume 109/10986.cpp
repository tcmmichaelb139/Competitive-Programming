#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> q;
    bool vis[n]; memset(vis, false, sizeof(vis));
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> k = q.top();
        q.pop();
        if (k.second == t) {
            cout << k.first;
            return;
        }
        if (vis[k.second]) continue;
        vis[k.second] = true;
        for (auto i: adj[k.second])
            q.push({i.first+k.first, i.second});
    }
    cout << "unreachable";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

