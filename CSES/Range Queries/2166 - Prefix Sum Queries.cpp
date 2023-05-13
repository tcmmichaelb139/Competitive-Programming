#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long mxl;
    long long sum;
};

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0};
    T cmb(T a, T b) {
        Node res = ID;
        res.mxl = max(res.mxl, max(a.mxl, a.sum + b.mxl));
        res.sum = a.sum + b.sum;
        return res;
    }
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
    vector<Node> v(n + 1);
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        long long mx = max(a, 0ll);
        v[i] = {mx, a};
    }

    Seg<Node, 1 << 18> seg;
    seg.build(v);

    while (q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long mx = max(c, 0ll);
            seg.upd((int)b, {mx, c});
        } else {
            Node res = seg.query(b, c);
            cout << max(res.sum, res.mxl) << '\n';
        }
    }
}
