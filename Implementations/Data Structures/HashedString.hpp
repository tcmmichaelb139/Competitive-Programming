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
