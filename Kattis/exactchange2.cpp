#include "bits/stdc++.h"
using namespace std;

void solve() {
    int t, n;
    cin >> t >> n;

    int mn = 1e9;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= t)
            mn = min(mn, v[i]);
    }

    int mx = t * 2;
    vector<int> dp(mx, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = mx - 1; j >= 0; j--)
            if (j + v[i] < mx)
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);

    for (int i = t; i < mx; i++)
        if (dp[i] != 1e9) {
            cout << i << ' ' << dp[i] << '\n';
            return;
        }

    cout << mn << ' ' << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
