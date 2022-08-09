#include "bits/stdc++.h"
using namespace std;

const int MAXH = 1e3 + 1;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    pair<int, int> pre[n + 1][MAXH];
    int dp[n + 1][MAXH];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < MAXH; j++)
            dp[i][j] = 1e9, pre[i][j] = {-1, -1};

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAXH; j++) {
            if (j + v[i] < MAXH)
                if (dp[i + 1][j + v[i]] > dp[i][j])
                    dp[i + 1][j + v[i]] = max(dp[i][j], j + v[i]), pre[i + 1][j + v[i]] = {i, j};
            if (j - v[i] >= 0)
                if (dp[i + 1][j - v[i]] > dp[i][j])
                    dp[i + 1][j - v[i]] = dp[i][j], pre[i + 1][j - v[i]] = {i, j};
        }
    }

    if (dp[n][0] == 1e9)
        cout << "IMPOSSIBLE\n";
    else {
        string ans = "";
        for (pair<int, int> i = {n, 0}; i.first != 0; i = pre[i.first][i.second]) {
            if (i.second > pre[i.first][i.second].second)
                ans += 'U';
            else
                ans += 'D';
        }

        reverse(begin(ans), end(ans));

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
