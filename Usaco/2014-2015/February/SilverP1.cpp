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

    string str;
    int updi = 0;
    string res;

   public:
    HashedString(string s) {
        str = s;
        h.push_back(0);
        for (int i = 0; s[i]; i++) {
            p.push_back(mod_mul(p[i], BASE));
        }
    }

    void updateHash() {
        if (updi >= str.length()) return;
        h.push_back((mul(h.back(), BASE) + str[updi] - 'a' + 1) % MOD);
        res += str[updi];
        updi++;
    }

    void remHash(int k) {
        while (k--)
            h.pop_back(), res.pop_back();
    }

    long long getHash(int len) {
        if (h.size() < len + 2) return -1;
        long long ans = (h[h.size() - 1] - mod_mul(h[h.size() - len - 2], p[len + 1])) % MOD;
        return ans < 0 ? ans + MOD : ans;
    }

    string getRes() { return res; }

    long long oneTimeHash(string s) {
        long long k = 0;
        for (int i = 0; s[i]; i++)
            k = (mul(k, BASE) + s[i] - 'a' + 1) % MOD;
        return k;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::p = {1};
const long long HashedString::BASE = uniform_int_distribution<long long>(0, MOD - 1)(rng);

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    HashedString h(s);

    long long ht = h.oneTimeHash(t);
    for (int i = 0; i < t.length(); i++)
        h.updateHash();

    for (int i = 0; i <= s.length() - t.length(); i++) {
        if (h.getHash(t.length() - 1) == ht) {
            h.remHash(t.length());
        }
        h.updateHash();
    }

    cout << h.getRes() << '\n';
}
