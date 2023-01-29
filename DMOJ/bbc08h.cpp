#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;

long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }
long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }

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

long long solve(long long n) {
    long long ans = 1;
    for (int i = 2 * n; i > n; i--)
        ans = mult(ans, i);
    for (int i = 2; i <= n; i++)
        ans = mult(ans, binpow(i, MOD - 2));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    cout << solve(n + 1) - 1 << '\n';
}
