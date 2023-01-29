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
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long dp[n + 1][k + 2];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k + 1; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;

    vector<long long> pre;
    pre.push_back(0);
    for (int i = 0; i < n; i++)
        pre.push_back(v[i] + *(--end(pre)));

    Seg<long long> seg;
    seg.init(n + 1);
    for (int i = 0; i < n; i++)
        seg.upd(i, v[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] == 1e18) continue;
            for (int a = 1; a <= n; a++) {
                if (i + a <= n)
                    dp[i + a][j + 1] = min(dp[i + a][j + 1], dp[i][j] + seg.query(i, i + a - 1) * a - (pre[i + a] - pre[i]));
            }
        }
    }
    cout << dp[n][k + 1] << '\n';
}
