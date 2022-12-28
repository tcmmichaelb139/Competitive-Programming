#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 1;

long long n, a, b;
long long dp[MAXN];

long long bs(long long k) {
    if (k <= 1) return 0;
    if (dp[k] != -1) return dp[k];

    long long mn = 1e18;

    long long pre = 0;

    for (int i = 2; i <= k; i++) {
        long long cur = (k + i - 1) / i;

        mn = min(mn, bs(cur) + b * (i - 1) + a);
    }

    return dp[k] = mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    memset(dp, -1, sizeof dp);

    cout << bs(n) << '\n';
}
