#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, l;
    cin >> n >> l;
    vector<long long> val(n);
    vector<vector<long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            long long a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    long long dp[1 << n];
    for (int i = 0; i < 1 << n; i++)
        dp[i] = 0;

    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            if (upper_bound(begin(v[j]), end(v[j]), dp[i]) == v[j].begin()) continue;

            long long ub = *--upper_bound(begin(v[j]), end(v[j]), dp[i]);

            if (val[j] + ub < dp[i]) continue;

            dp[i | (1 << j)] = max(dp[i | (1 << j)], val[j] + ub);
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 1 << n; i++) {
        if (dp[i] >= l)
            ans = min(ans, __builtin_popcount(i));
    }
    if (ans == 1e9)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
