#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> v(n), w(n);
    for (int i = 0; i < m; i++) cin >> v[i] >> w[i];
    vector<long long> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= 0; j--) {
            if (j + v[i] <= n)
                dp[j + v[i]] = max(dp[j + v[i]], dp[j] + v[i] * w[i]);
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}
