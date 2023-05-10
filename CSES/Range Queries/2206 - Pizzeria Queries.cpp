#include "bits/stdc++.h"
using namespace std;

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = 1e9;
    T cmb(T a, T b) { return min(a, b); }
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
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        v2[i] = v1[i] + n - i - 1;
        v1[i] += i;
    }

    Seg<int, 1 << 18> seg1, seg2;
    seg1.build(v1);
    seg2.build(v2);

    for (int i = 0; i < q; i++) {
        int j;
        cin >> j;
        if (j == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            seg1.upd(p, x + p);
            seg2.upd(p, x + n - p - 1);
        } else {
            int k;
            cin >> k;
            k--;
            cout << min(seg1.query(k, n - 1) - k, seg2.query(0, k) - (n - k - 1)) << '\n';
        }
    }
}
