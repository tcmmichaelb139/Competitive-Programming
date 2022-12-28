#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("recording.in", "r", stdin);
    freopen("recording.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    v[0] = {-1, -1};
    for (int i = 1; i <= n; ++i)
        cin >> v[i].first >> v[i].second;

    sort(begin(v), end(v));

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = max(i, j) + 1; k <= n; k++) {
                if (v[i].second <= v[k].first)
                    dp[k][j] = max(dp[k][j], dp[i][j] + 1);
                if (v[j].second <= v[k].first)
                    dp[i][k] = max(dp[i][k], dp[i][j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}
