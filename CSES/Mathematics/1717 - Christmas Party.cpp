#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = 0;
    for (long long i = 2; i <= n; i++)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[n] << '\n';
}
