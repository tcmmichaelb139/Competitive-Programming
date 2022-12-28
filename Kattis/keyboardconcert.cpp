#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<set<int>> v(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[i].insert(a);
        }
    }

    vector<vector<int>> pos(m);
    vector<int> o(m);
    for (int i = 0; i < m; i++) {
        cin >> o[i];
        for (int j = 0; j < n; j++)
            if (v[j].find(o[i]) != v[j].end())
                pos[i].push_back(j);
    }

    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1e9;

    int pre_min = 0;
    for (int i = 0; i < pos[0].size(); i++)
        dp[0][pos[0][i]] = 0;

    for (int i = 1; i < m; i++) {
        int new_min = 1e9;
        for (int j = 0; j < pos[i].size(); j++) {
            dp[i][pos[i][j]] = min(dp[i][pos[i][j]], dp[i - 1][pos[i][j]]);
            dp[i][pos[i][j]] = min(dp[i][pos[i][j]], pre_min + 1);
            new_min = min(new_min, dp[i][pos[i][j]]);
        }
        pre_min = new_min;
    }

    int ans = 1e9;
    for (int i = 0; i <= n; i++)
        ans = min(ans, dp[m - 1][i]);

    cout << ans << '\n';
}
