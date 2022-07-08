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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    long long ans = 1;
    map<long long, long long> m;
    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
        ans *= i + 1;
        ans %= mod;
    }
    for (auto i : m)
        for (; i.second > 1; i.second--)
            ans = ans * binpow(i.second, mod - 2) % mod;
    cout << ans << '\n';
}
