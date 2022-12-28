#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Hoof = 0, Paper = 1, Scissors = 2

    auto check = [](int a, int b) {
        return (a + 1) % 3 == b;
    };

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'H')
            v[i] = 0;
        else if (c == 'P')
            v[i] = 1;
        else if (c == 'S')
            v[i] = 2;
    }

    int dp[n + 1][k + 1][3];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int a = 0; a < 3; a++)
                dp[i][j][a] = -1e9;

    for (int i = 0; i < 3; i++)
        dp[0][0][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int a = 0; a < 3; a++) {
                if (j <= k)
                    dp[i + 1][j][a] = max(dp[i + 1][j][a], dp[i][j][a] + check(v[i], a));

                if (j < k)
                    for (int b = 0; b < 3; b++)
                        dp[i + 1][j + 1][b] = max(dp[i + 1][j + 1][b], dp[i][j][a] + check(v[i], b));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < 3; j++)
            ans = max(ans, dp[n][i][j]);
    cout << ans << '\n';
}
