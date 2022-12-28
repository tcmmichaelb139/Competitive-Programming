#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    long long k, r;
    cin >> k >> r;
    vector<long long> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];

    vector<pair<long long, long long>> c(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> c[i].first >> c[i].second;

    long long dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e18;

    dp[0][1] = 0;
    for (long long i = 0; i < n; i++)
        for (long long j = 1; j <= m; j++)
            for (long long a = 1; a <= m; a++)
                if (abs(a - j) * k <= l[i])
                    dp[i + 1][a] = min(dp[i + 1][a], dp[i][j] + l[i] + abs(a - j) * r + (i == n - 1 ? 0 : c[i].first + a * c[i].second));

    cout << dp[n][1] << '\n';
}
