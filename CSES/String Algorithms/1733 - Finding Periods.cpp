#include "bits/stdc++.h"
using namespace std;

class HashedString {
   private:
    static const long long MOD = (1ll << 61) - 1;
    static const long long BASE;

    static vector<long long> p;

    vector<long long> h;

    __int128 mul(long long a, long long b) { return (__int128)a * b; }
    long long mod_mul(long long a, long long b) { return mul(a, b) % MOD; }

   public:
    HashedString(string s) : h(s.length() + 1) {
        h[0] = 0;
        for (int i = 0; s[i]; i++) {
            h[i + 1] = (mul(h[i], BASE) + s[i] - 'a' + 1) % MOD;
            p.push_back(mod_mul(p[i], BASE));
        }
    }

    long long getHash(int l, int r) {
        long long ans = (h[r + 1] - mod_mul(h[l], p[r - l + 1])) % MOD;
        return ans < 0 ? ans + MOD : ans;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::p = {1};
const long long HashedString::BASE = uniform_int_distribution<long long>(0, MOD - 1)(rng);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    HashedString h(s);

    vector<bool> ans(s.length() + 1, false);

    for (int i = 1; i <= s.length(); i++) {
        if (ans[i]) continue;
        bool ok = true;
        long long hv = h.getHash(0, i - 1);
        for (int j = 0; j < s.length(); j += i) {
            if (s.length() > j + i - 1) {
                if (hv != h.getHash(j, j + i - 1)) {
                    ok = false;
                    break;
                }
            } else {
                if (h.getHash(0, s.length() - j - 1) != h.getHash(j, s.length() - 1))
                    ok = false;
            }
        }
        if (ok)
            for (int j = 0; j < s.length(); j += i + 1)
                ans[i] = true;
    }
    for (int i = 1; i <= s.length(); i++)
        if (ans[i])
            cout << i << ' ';
    cout << '\n';
}
