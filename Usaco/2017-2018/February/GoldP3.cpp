#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int dp[n + 1][n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = 1e9;
    dp[0][1][0] = v[0] != 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j][k] == (int)(1e9)) continue;
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + (v[i + 1] != i - k + 1));
                dp[i + 1][j + 1][i + 1] = min(dp[i + 1][j + 1][i + 1], dp[i][j][k] + (v[i + 1] != 0));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = 1e9;
        for (int k = 0; k <= n; k++) {
            ans = min(ans, dp[n - 1][i][k]);
        }
        cout << ans << '\n';
    }
}
