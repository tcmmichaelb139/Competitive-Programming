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

    string s, t;
    cin >> s >> t;

    if (s.length() > t.length()) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> fs(26, 0), ft(26, 0);
    for (int i = 0; i < s.length(); i++) {
        fs[s[i] - 'a']++;
        ft[t[i] - 'a']++;
    }

    HashedString h(t);

    set<long long> ans;

    if (fs == ft)
        ans.insert(h.getHash(0, s.length() - 1));

    for (int i = 0; i < t.length() - s.length(); i++) {
        ft[t[i] - 'a']--;
        ft[t[i + s.length()] - 'a']++;
        if (fs == ft)
            ans.insert(h.getHash(i + 1, s.length() + i));
    }
    cout << ans.size() << '\n';
}
