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

    int n;
    cin >> n;
    vector<long long> base(n), pow(n);
    long long numDiv = 1, sumDiv = 1, prodDiv = 1, numDiv2 = 1;
    for (int i = 0; i < n; i++) {
        cin >> base[i] >> pow[i];
    }

    for (int i = 0; i < n; i++) {
        numDiv = mult(numDiv, pow[i] + 1);
        sumDiv = mult(sumDiv, mult(binpow(base[i], pow[i] + 1) - 1, binpow(base[i] - 1, MOD - 2)));
        prodDiv = mult(binpow(prodDiv, pow[i] + 1), binpow(binpow(base[i], pow[i] * (pow[i] + 1) / 2), numDiv2));
        numDiv2 = numDiv2 * (pow[i] + 1) % (MOD - 1);
    }

    cout << numDiv << ' ' << sumDiv << ' ' << prodDiv << '\n';
}
