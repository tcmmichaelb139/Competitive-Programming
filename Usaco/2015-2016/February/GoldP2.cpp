#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];

    int ans = 1e9;
    for (int x = 0; x < n; x++) {
        int dp[n + 1][n + 1][k + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int a = 0; a <= k; a++)
                    dp[i][j][a] = 1e9;
        dp[0][0][1] = 0;

        for (int a = 0; a < n; a++) {
            for (int b = 0; b <= a; b++) {
                for (int c = 1; c <= k; c++) {
                    dp[a + 1][a][c + 1] = min(dp[a + 1][a][c + 1], dp[a][b][c]);
                    dp[a + 1][b][c] = min(dp[a + 1][b][c], dp[a][b][c] + r[a] * (a - b));
                }
            }
        }

        for (int b = 0; b <= n; b++)
            for (int c = 1; c <= k; c++)
                ans = min(ans, dp[n][b][c]);

        rotate(begin(r), begin(r) + 1, end(r));
    }
    cout << ans << '\n';
}
