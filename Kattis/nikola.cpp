#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1e9;

    dp[1][0] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i > 0; i--)
            if (i - j > 0)
                dp[i - j][j] = min(dp[i - j][j], dp[i][j] + v[i - j]);
        for (int i = 1; i < n; i++)
            if (i + j < n)
                dp[i + j + 1][j + 1] = min(dp[i + j + 1][j + 1], dp[i][j] + v[i + j + 1]);
    }

    int ans = 1e9;
    for (int i = 0; i <= n; i++)
        ans = min(ans, dp[n][i]);

    cout << ans << '\n';
}
