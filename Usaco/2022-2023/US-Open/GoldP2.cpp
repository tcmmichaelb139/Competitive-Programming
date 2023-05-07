#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    string des = "bessie";
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(6, {-1e9, -1e9}));
    dp[0][0] = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            if (dp[i][j].first < 0) continue;
            if (dp[i + 1][j].first < dp[i][j].first)
                dp[i + 1][j] = {dp[i][j].first, dp[i][j].second + cost[i]};
            if (dp[i + 1][j].first == dp[i][j].first)
                dp[i + 1][j].second = min(dp[i + 1][j].second, dp[i][j].second + cost[i]);
            if (dp[i + 1][0].first < dp[i][j].first)
                dp[i + 1][0] = dp[i][j];
            if (dp[i + 1][0].first == dp[i][j].first)
                dp[i + 1][0].second = min(dp[i + 1][0].second, dp[i][j].second);
            if (s[i] == des[j]) {
                if (j == 5) {
                    if (dp[i + 1][0].first < dp[i][j].first + 1)
                        dp[i + 1][0] = {dp[i][j].first + 1, dp[i][j].second};
                    if (dp[i + 1][0].first == dp[i][j].first + 1)
                        dp[i + 1][0].second = min(dp[i + 1][0].second, dp[i][j].second);
                } else {
                    if (dp[i + 1][j + 1].first < dp[i][j].first)
                        dp[i + 1][j + 1] = {dp[i][j].first, dp[i][j].second};
                    if (dp[i + 1][j + 1].first == dp[i][j].first)
                        dp[i + 1][j + 1].second = min(dp[i + 1][j + 1].second, dp[i][j].second);
                }
            }
        }
    }
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < 6; i++) {
        if (ans.first < dp[n][i].first)
            ans = dp[n][i];
        if (ans.first == dp[n][i].first)
            ans.second = min(ans.second, dp[n][i].second);
    }
    cout << ans.first << '\n'
         << ans.second << '\n';
}
