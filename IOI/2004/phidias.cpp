#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, h, n;
    cin >> w >> h >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    int dp[w + 1][h + 1];
    for (int i = 0; i <= w; i++)
        for (int j = 0; j <= h; j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            for (int a = 0; a < n; a++) {
                if (i - v[a].first == 0 && j - v[a].second == 0)
                    dp[i][j] = 0;
                else {
                    if (i - v[a].first >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - v[a].first][j] + (j % v[a].second) * v[a].first);
                        dp[i][j] = min(dp[i][j], dp[i - v[a].first][j] + dp[v[a].first][j]);
                        dp[i][j] = min(dp[i][j], dp[i - v[a].first][j] + dp[v[a].first][j % v[a].second]);
                    }
                    if (j - v[a].second >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i][j - v[a].second] + (i % v[a].first) * v[a].second);
                        dp[i][j] = min(dp[i][j], dp[i][j - v[a].second] + dp[i][v[a].second]);
                        dp[i][j] = min(dp[i][j], dp[i][j - v[a].second] + dp[i % v[a].first][v[a].second]);
                    }
                }
            }
        }
    }
    for (int i = 0; i <= w; i++)
        for (int j = 0; j <= h; j++)
            dp[w][h] = min(dp[w][h], w * h - i * j + dp[i][j]);
    cout << dp[w][h] << '\n';
}
