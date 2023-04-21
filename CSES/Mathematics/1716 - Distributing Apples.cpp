#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long fact[2000001], inv[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[1] = 1;
    inv[1] = inv[0] = 1;
    for (int i = 2; i <= 2000000; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2);
    }

    long long a, b;
    cin >> a >> b;
    cout << (fact[a + b - 1] * inv[b] % mod) * inv[a - 1] % mod << '\n';
}