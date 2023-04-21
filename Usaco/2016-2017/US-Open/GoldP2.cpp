#include "bits/stdc++.h"
using namespace std;

class HashedString {
   private:
    static const long long MOD = (1ll << 61) - 1;
    static const long long BASE;
    static const int MAXN = 501;
    long long p[MAXN], h[MAXN];

    __int128 mul(long long a, long long b) { return (__int128)a * b; }
    long long mod_mul(long long a, long long b) { return mul(a, b) % MOD; }

   public:
    void init(string s) {
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

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<HashedString> hs(n), hp(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hs[i].init(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hp[i].init(s);
    }

    int l = 0, r = 0, ans = 1e9;
    while (l != m && r != m) {
        set<long long> s, p;

        for (int a = 0; a < n; a++)
            s.insert(hs[a].getHash(l, r));
        for (int a = 0; a < n; a++)
            p.insert(hp[a].getHash(l, r));

        bool ok = true;
        for (auto a : s)
            if (p.find(a) != p.end())
                ok = false;
        if (ok) {
            ans = min(ans, r - l + 1);
            if (l == r)
                r++;
            else
                l++;
        } else
            r++;
    }

    cout << ans << '\n';
}
