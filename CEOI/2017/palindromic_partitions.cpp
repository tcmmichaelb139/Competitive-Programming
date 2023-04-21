#include "bits/stdc++.h"
using namespace std;

class HashedString {
   private:
    static const long long MOD = (1ll << 61) - 1;
    static const long long BASE;
    static const int MAXN = 1e6 + 1;
    long long p[MAXN], h[MAXN];

    __int128 mul(long long a, long long b) { return (__int128)a * b; }
    long long mod_mul(long long a, long long b) { return mul(a, b) % MOD; }

   public:
    HashedString(string s) {
        h[0] = 0;
        p[0] = 1;
        for (int i = 0; s[i]; i++) {
            h[i + 1] = (mul(h[i], BASE) + s[i] - 'a' + 1) % MOD;
            p[i + 1] = mod_mul(p[i], BASE);
        }
    }

    long long getHash(int l, int r) {
        long long ans = (h[r + 1] - mod_mul(h[l], p[r - l + 1])) % MOD;
        return ans < 0 ? ans + MOD : ans;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const long long HashedString::BASE = uniform_int_distribution<long long>(0, MOD - 1)(rng);

void solve() {
    string s;
    cin >> s;

    HashedString h(s);

    int chunks = 0;
    bool fend = false;
    for (int i = 0; i < s.length() / 2;) {
        bool found = false;
        for (int j = i; j < s.length() / 2; j++) {
            if (h.getHash(i, j) == h.getHash(s.length() - j - 1, s.length() - i - 1)) {
                i = j + 1;
                found = true;
                chunks += 2;
                if (i == s.length() / 2)
                    fend = true;
                break;
            }
        }
        if (!found) break;
    }
    if (!fend || s.length() & 1)
        chunks++;
    cout << max(1, chunks) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
