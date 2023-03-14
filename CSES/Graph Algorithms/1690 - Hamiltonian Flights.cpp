#include "bits/stdc++.h"
using namespace std;

long long MOD = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % MOD; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    long long dp[1 << n][n];
    memset(dp, 0, sizeof dp);

    dp[1][0] = 1;
    for (int i = 1; i < 1 << n; i++) {
        if (!(i & 1)) continue;
        if (i & (1 << (n - 1)) && i != (1 << n) - 1) continue;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (auto k : adj[j])
                    if (!(i & (1 << k)))
                        dp[i | (1 << k)][k] = add(dp[i | (1 << k)][k], dp[i][j]);
    }

    cout << dp[(1 << n) - 1][n - 1] << '\n';
}
