#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[n][n];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        dp[i][i] = v[i];

    int ans = 0;
    for (int len = 1; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            for (int x = l; x < r; x++) {
                if (dp[l][x] == dp[x + 1][r] && dp[l][x] != 0) {
                    assert(dp[l][r] <= dp[l][x] + 1);
                    dp[l][r] = dp[l][x] + 1;
                    ans = max(ans, dp[l][r]);
                }
            }
        }
    }

    cout << ans << '\n';
}
