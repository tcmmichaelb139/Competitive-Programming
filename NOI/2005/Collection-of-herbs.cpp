#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m;
    cin >> t >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= 0; j--) {
            if (j + v[i].first <= t)
                dp[j + v[i].first] =
                    max(dp[j + v[i].first], dp[j] + v[i].second);
        }
    }
    int ans = 0;
    for (int i = 0; i <= t; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}
