#include "bits/stdc++.h"
using namespace std;

const int MOD = 998244353;

long long add(long long a, long long b) { return ((a % MOD + b % MOD) % MOD + MOD) % MOD; }
long long mult(long long a, long long b) { return (a % MOD) * (b % MOD) % MOD; }

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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    long long a = 1, b = 0;
    queue<pair<long long, long long>> q;
    while (t--) {
        int k;
        cin >> k;
        if (k == 0) {
            long long x, y;
            cin >> x >> y;
            q.push({x, y});
            y = add(y, mult(x, b));
            x = mult(x, a);
            a = x, b = y;
        } else if (k == 1) {
            pair<long long, long long> x = q.front();
            q.pop();
            a = mult(a, binpow(x.first, MOD - 2));
            b = add(b, -mult(a, x.second));
        } else {
            long long x;
            cin >> x;
            cout << add(mult(x, a), b) << '\n';
        }
    }
}
