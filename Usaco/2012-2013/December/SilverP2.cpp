#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(begin(v), end(v));

    pair<long long, long long> dp[n + 1];

    for (int i = 0; i <= n; i++) dp[i] = {1e9, 0};
    dp[0] = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long k1 = dp[j + 1].first * a + (dp[j + 1].second * b) / 2;
            long long k2 = (dp[i].first + 1) * a + ((dp[i].second + v[j] - v[i]) * b) / 2;
            if (k1 > k2)
                dp[j + 1] = {dp[i].first + 1, dp[i].second + v[j] - v[i]};
        }
    }

    cout << (dp[n].first * a) + (dp[n].second * b) / 2 << ((dp[n].second * b) & 1 ? ".5" : "") << '\n';
}
