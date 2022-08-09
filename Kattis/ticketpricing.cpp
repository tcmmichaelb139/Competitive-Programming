#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<pair<vector<int>, vector<int>>> v(w + 2);
    for (int i = w + 1; i > 0; i--) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[i].first.push_back(a);
        }
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[i].second.push_back(a);
        }
    }

    int dp[w + 2][n + 1];
    int mn[w + 2][n + 1];
    for (int i = 0; i <= w + 1; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1e9, mn[i][j] = 1e9;

    dp[w + 1][n] = 0;
    for (int i = w + 1; i > 0; i--) {
        for (int j = 0; j <= n; j++) {
            for (int a = 0; a < (int)v[i].first.size(); a++) {
                int tickets = min(j, v[i].second[a]);
                if (dp[i - 1][j - tickets] < dp[i][j] + v[i].first[a] * tickets) {
                    dp[i - 1][j - tickets] = dp[i][j] + v[i].first[a] * tickets;
                    if (i == w + 1)
                        mn[i - 1][j - tickets] = v[i].first[a];
                    else
                        mn[i - 1][j - tickets] = mn[i][j];
                } else if (dp[i - 1][j - tickets] == dp[i][j] + v[i].first[a] * tickets)
                    mn[i - 1][j - tickets] = min(mn[i - 1][j - tickets], mn[i][j]);
            }
        }
    }

    int ans = -1e9;
    int mnans = 1e9;
    for (int i = 0; i <= n; i++) {
        if (ans < dp[0][i])
            ans = dp[0][i], mnans = mn[0][i];
        else if (ans == dp[0][i])
            mnans = min(mnans, mn[0][i]);
    }
    cout << ans << '\n';
    cout << mnans << '\n';
}
