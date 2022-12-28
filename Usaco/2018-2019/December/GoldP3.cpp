#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
    const T ID = 0;
    T cmb(T a, T b) { return max(a, b); }
    int N;
    vector<T> seg;
    void init(int _N) {
        for (N = 1; N < _N;) N *= 2;
        seg.assign(2 * N, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, int val) {
        seg[p += N] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(rb, seg[--r]);
        }
        return cmb(ra, rb);
    }
};

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long long dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1e9;

    Seg<long long> seg;
    seg.init(n + 1);
    for (int i = 0; i < n; i++)
        seg.upd(i, v[i]);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (dp[i] == -1e9) continue;
            if (i + j > n) break;
            dp[i + j] = max(dp[i + j], dp[i] + seg.query(i, i + j - 1) * j);
        }
    }
    cout << dp[n] << '\n';
}
