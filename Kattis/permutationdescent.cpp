#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1001113;

void solve() {
    auto add = [](long long a, long long b) {
        return (a + b) % MOD;
    };

    auto mult = [](long long a, long long b) {
        return a * b % MOD;
    };

    int k, n, t;
    cin >> k >> n >> t;

    long long dp[n + 1][n];
    memset(dp, 0, sizeof dp);

    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = add(dp[i][j], mult(dp[i - 1][j], j + 1));
            if (j > 0)
                dp[i][j] = add(dp[i][j], mult(dp[i - 1][j - 1], i - j));
        }
    }

    cout << k << ' ' << dp[n][t] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
