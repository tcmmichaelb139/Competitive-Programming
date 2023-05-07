#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        num[i] = s[i] - 'a';
    vector<vector<int>> a(m, vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> dist = a;
    for (int z = 0; z < m; z++)
        for (int x = 0; x < m; x++)
            for (int y = 0; y < m; y++)
                dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);

    vector<vector<int>> cost(m, vector<int>(n - k + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++)
            cost[i][0] += dist[num[j]][i];
        for (int j = 1; j <= n - k; j++)
            cost[i][j] = cost[i][j - 1] - dist[num[j - 1]][i] + dist[num[j + k - 1]][i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m, 1e9));

    for (int i = 0; i < m; i++)
        dp[k][i] = cost[i][0];

    for (int i = k; i < n; i++) {
        int mn = 1e9;
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist[num[i]][j]);
            mn = min(mn, dp[i][j]);
        }
        if (i <= n - k)
            for (int x = 0; x < m; x++)
                dp[i + k][x] = min(dp[i + k][x], mn + cost[x][i]);
    }

    int ans = 1e9;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}
