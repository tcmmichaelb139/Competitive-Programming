#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> w(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> h[i];

    pair<int, int> dp[n + 1][c + 1];
    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= c; k++)
            dp[i][k] = {1e9, 1e9};

    dp[0][0] = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= c; k++) {
            int j = dp[i][k].second;
            if (w[i] + k <= c)
                if (dp[i + 1][k + w[i]].first > dp[i][k].first - j + max(j, h[i]))
                    dp[i + 1][k + w[i]] = {dp[i][k].first - j + max(j, h[i]), max(j, h[i])};
            if (dp[i + 1][w[i]].first > dp[i][k].first + h[i])
                dp[i + 1][w[i]] = {dp[i][k].first + h[i], h[i]};
        }
    }

    int ans = 1e9;
    for (int j = 0; j <= c; j++)
        ans = min(ans, dp[n][j].first);
    cout << ans << '\n';
}
