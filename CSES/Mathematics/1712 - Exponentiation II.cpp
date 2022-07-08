#include "bits/stdc++.h"
using namespace std;

const long long mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    if (a == 0 && b == 0) return 1;
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, mod - 1), mod) << '\n';
    }
}
