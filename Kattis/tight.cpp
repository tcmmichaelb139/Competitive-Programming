#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    while (cin >> k >> n) {
        double total = 1;
        for (int i = 0; i < n; i++)
            total *= k + 1;

        double dp[n + 1][k + 1];
        memset(dp, 0, sizeof dp);

        for (int i = 0; i <= k; i++)
            dp[1][i] = 1;

        for (int i = 1; i < n; i++)
            for (int j = 0; j <= k; j++) {
                if (j < k)
                    dp[i + 1][j + 1] += dp[i][j];

                dp[i + 1][j] += dp[i][j];

                if (j > 0)
                    dp[i + 1][j - 1] += dp[i][j];
            }

        double ans = 0;
        for (int i = 0; i <= k; i++)
            ans += dp[n][i];

        ans /= total;

        cout << setprecision(12) << ans * 100 << '\n';
    }
}
