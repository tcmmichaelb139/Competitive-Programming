/*
ID: tcmmich1
TASK: rockers
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

const int MIN = -1e9;

int main() {
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, m;
    cin >> n >> t >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    pair<int, int> dp[1 << 20];  // time used up

    for (int i = 0; i < 1 << n; i++)
        dp[i] = {MIN, MIN};

    dp[0] = {0, 0};
    for (int i = 0; i < 1 << n; i++) {
        if (dp[i].first == MIN) continue;
        int num = __builtin_popcount(i);
        for (int k = 0; k < n; k++) {
            if (num) {
                if (i & (1 << k)) num--;
                continue;
            }
            if (dp[i].first + 1 < m && v[k] <= t) {
                if (dp[i | (1 << k)].first == MIN || dp[i | (1 << k)].first > dp[i].first + 1) {
                    dp[i | (1 << k)].first = dp[i].first + 1;
                    dp[i | (1 << k)].second = v[k];
                } else if (dp[i | (1 << k)].first == dp[i].first + 1 && dp[i | (1 << k)].second > v[k]) {
                    dp[i | (1 << k)].second = v[k];
                }
            }
            if (dp[i].second + v[k] <= t) {
                if (dp[i | (1 << k)].first == MIN || dp[i | (1 << k)].first > dp[i].first) {
                    dp[i | (1 << k)].first = dp[i].first;
                    dp[i | (1 << k)].second = dp[i].second + v[k];
                } else if (dp[i | (1 << k)].first == dp[i].first || dp[i | (1 << k)].second > dp[i].second + v[k]) {
                    dp[i | (1 << k)].second = dp[i].second + v[k];
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < 1 << n; i++) {
        if (dp[i].first != MIN) {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    cout << ans << '\n';
}
