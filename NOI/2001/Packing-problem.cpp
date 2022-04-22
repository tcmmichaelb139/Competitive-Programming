#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<bool> dp(m, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= 0; j--)
            if (dp[j] && j + v[i] <= m) dp[j + v[i]] = true;
    int ans = 0;
    for (int i = 0; i <= m; i++)
        if (dp[i]) ans = max(ans, i);
    cout << m - ans << '\n';
}
