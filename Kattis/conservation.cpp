#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> lab(n);
    for (int i = 0; i < n; i++) {
        cin >> lab[i];
        lab[i]--;
    }
    vector<vector<int>> adj(n);
    vector<int> par(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        par[b]++;
    }

    long long ans = 1e18;
    for (int j = 0; j < 2; j++) {
        vector<queue<int>> q(2);
        vector<int> p = par;
        for (int i = 0; i < n; i++) {
            if (par[i]) continue;
            if (lab[i])
                q[1].push(i);
            else
                q[0].push(i);
        }
        long long cur = 0;
        bool q0q1 = j;
        while (!q[0].empty() || !q[1].empty()) {
            if (!q[q0q1].size())
                q0q1 = !q0q1, cur++;

            int v = q[q0q1].front();
            q[q0q1].pop();

            for (auto u : adj[v]) {
                if (--p[u]) continue;

                q[lab[u]].push(u);
            }
        }
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
