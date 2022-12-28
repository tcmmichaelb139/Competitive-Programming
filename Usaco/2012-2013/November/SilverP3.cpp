#include "bits/stdc++.h"
using namespace std;

const int MOD = 2012;

int main() {
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto add = [&](long long a, long long b) { return (a + b) % MOD; };

    string s;
    cin >> s;
    int n = s.length();

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    int cur = 0;

    for (int i = 0; i < n; i++) {
        cur += (s[i] == '(' ? 1 : -1);
        for (int j = 0; j < n; j++) {
            if (j > cur) continue;
            if (s[i] == '(') {
                dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
                if (j > 0)
                    dp[i + 1][j] = add(dp[i + 1][j], dp[i][j - 1]);
            } else {
                dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j] = add(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[n][0] << '\n';
}
