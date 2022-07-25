#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[n + 1][t + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= t; j++)
            dp[i][j] = 1e9;

    dp[0][0] = 0;

    pair<int, int> pre[n + 1][t + 1];
    pre[0][0] = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = t; j >= 0; j--) {
            if (j + v[i] <= t) {
                if (dp[i + 1][j + v[i]] > dp[i][j]) {
                    dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j]);
                    pre[i + 1][j + v[i]] = {i, j};
                }
            }
            if (dp[i][j] + v[i] <= t) {
                if (dp[i + 1][j] > dp[i][j] + v[i]) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + v[i]);
                    pre[i + 1][j] = {i, j};
                }
            }
        }
    }

    for (int j = 0; j <= t; j++)
        if (dp[n][j] != 1e9) {
            vector<int> ans;
            int tl = t, tr = t;
            int i = n;
            for (pair<int, int> a = pre[n][j]; a.first != -1; a = pre[a.first][a.second]) {
                if (a.second == j) {
                    tl -= dp[i][j] - dp[a.first][a.second];
                    ans.push_back(tl);
                } else {
                    tr -= j - a.second;
                    ans.push_back(tr);
                }
                i = a.first;
                j = a.second;
            }
            reverse(begin(ans), end(ans));
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i + 1 == n];
            return 0;
        }
}

// dp[index][done time 1] = min done time 2;
