#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long lnr;  // left but no right
    long long rnl;  // right but no left
    long long blr;  // both left and right
    long long nlr;  // no left or right

    long long mx() { return max(max(lnr, rnl), max(blr, nlr)); }
};

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0, 0, 0};
    T cmb(T a, T b) {
        return {
            max(a.lnr + max(b.lnr, b.nlr), a.blr + b.nlr),
            max(max(a.rnl, a.nlr) + b.rnl, a.nlr + b.blr),
            max(max(a.blr + b.rnl, a.lnr + b.blr), a.lnr + b.rnl),
            max(max(a.rnl + b.nlr, a.nlr + b.lnr), a.nlr + b.nlr),
        };
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
    freopen("optmilk.in", "r", stdin);
    freopen("optmilk.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        v[i] = {0, 0, a, 0};
    }

    Seg<Node, 1 << 16> seg;
    seg.build(v);

    long long ans = 0;

    for (int i = 0; i < d; i++) {
        int j;
        long long m;
        cin >> j >> m;

        seg.upd(j - 1, {0, 0, m, 0});
        ans += seg.seg[1].mx();
    }
    cout << ans << '\n';
}
