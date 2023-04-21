#include <iostream>

#include "bits/stdc++.h"
using namespace std;

struct HashStr {
    const long long MOD = 1e9 + 7;
    /* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); */
    /* const long long base = uniform_int_distribution<long long>(0, MOD - 1)(rng); */
    const long long BASE = 9973;
    vector<long long> p;
    vector<long long> h;

    HashStr(string s) : h(s.length() + 1) {
        h[0] = 0;
        p.push_back(1);
        for (int i = 1; s[i]; ++i) {
            h[i] = (h[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
            p.push_back((p[i - 1] * BASE) % MOD);
        }
    }

    long long getHash(int l, int r) {
        int ans = (h[r] - h[l - 1] * p[r - l + 1]) % MOD;
        return ans < 0 ? ans + MOD : ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    s = " " + s;
    t = " " + t;

    HashStr h(s);

    long long ht = 0;
    for (int i = 1; t[i]; ++i) ht = (ht * h.BASE + t[i] - 'a' + 1) % h.MOD;

    int ans = 0;
    for (int l = 1, r = t.length() - 1; r < s.length(); l++, r++) {
        if (h.getHash(l, r) == ht)
            ans++;
    }
    cout << ans << '\n';
}
