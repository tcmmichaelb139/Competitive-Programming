#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1000000007;

long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();

    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        dp[i + 1][i] = 1;

    vector<long long> fac(501, 1);
    vector<long long> inv(501, 1);
    for (long long i = 2; i < 501; i++) {
        fac[i] = mult(fac[i - 1], i);
        inv[i] = binpow(fac[i], MOD - 2);
    }

    auto nCr = [&](long long a, long long b) {
        return mult(fac[a], mult(inv[b], inv[a - b]));
    };

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r += 2) {
            for (int x = l + 1; x <= r; x += 2) {
                if (s[l] == s[x]) {
                    dp[l][r] = add(dp[l][r], mult(mult(dp[l + 1][x - 1], dp[x + 1][r]), nCr((r - l + 1) / 2, (x - l + 1) / 2)));
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}
