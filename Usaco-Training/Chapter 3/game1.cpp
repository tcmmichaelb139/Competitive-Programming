/*
ID: tcmmich1
TASK: game1
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1e9;
    for (int i = 0; i < n; i++)
        dp[i][i] = v[i];

    for (int len = 1; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
        }
    }

    int diff = dp[0][n - 1];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    int ans1 = (diff + sum) / 2;
    int ans2 = sum - ans1;
    cout << ans1 << ' ' << ans2 << '\n';
}
