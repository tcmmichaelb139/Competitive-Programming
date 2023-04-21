#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    pair<int, long long> dp[1 << n];
    for (int i = 0; i < 1 << n; i++)
        dp[i] = {1e9, 1e9};
    dp[0] = {0, 0};
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                pair<int, long long> nval = dp[i];
                if (nval.second + v[j] > x)
                    nval.first++, nval.second = v[j];
                else
                    nval.second += v[j];
                if (nval.first < dp[i | (1 << j)].first)
                    dp[i | (1 << j)] = nval;
                if (nval.first == dp[i | (1 << j)].first)
                    dp[i | (1 << j)].second = min(dp[i | (1 << j)].second, nval.second);
            }
        }
    }
    cout << dp[(1 << n) - 1].first + (dp[(1 << n) - 1].second > 0) << '\n';
}
