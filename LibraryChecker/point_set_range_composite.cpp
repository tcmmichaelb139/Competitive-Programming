#include "bits/stdc++.h"
using namespace std;

const long long MOD = 998244353;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {1, 0};
    T cmb(T a, T b) { return {mult(a.first, b.first), add(mult(a.second, b.first), b.second)}; }
    T seg[2 * N];
    Seg() {
        for (int i = 0; i < 2 * N; i++)
            seg[i] = ID;
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void build(vector<T> &v, int p = 1, int L = 0, int R = N - 1) {
        if (L == R) {
            if (size(v) > L)
                seg[p] = v[L];
        } else {
            int M = (L + R) / 2;
            build(v, 2 * p, L, M);
            build(v, 2 * p + 1, M + 1, R);
            pull(p);
        }
    }
    void upd(int v, T val, int p = 1, int L = 0, int R = N - 1) {
        if (L == R) {
            seg[p] = val;
        } else {
            int M = (L + R) / 2;
            if (v <= M)
                upd(v, val, 2 * p, L, M);
            else
                upd(v, val, 2 * p + 1, M + 1, R);
            pull(p);
        }
    }
    T query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[p];
        int M = (L + R) / 2;
        return cmb(query(lo, hi, 2 * p, L, M), query(lo, hi, 2 * p + 1, M + 1, R));
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    Seg<pair<long long, long long>, 1 << 19> seg;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    seg.build(v);

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a) {
            pair<int, int> l = seg.query(b, c - 1);
            cout << add(mult(l.first, d), l.second) << '\n';
        } else {
            seg.upd(b, {c, d});
        }
    }
}
