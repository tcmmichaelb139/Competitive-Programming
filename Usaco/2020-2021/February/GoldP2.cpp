#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 1e9;

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int len = 1; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            if (v[l] == v[r] && len > 1) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
            }
            for (int x = l; x < r; x++) {
                if (v[x] == v[x + 1] || v[l] == v[r])
                    dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r] - 1);
                dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r]);
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}
