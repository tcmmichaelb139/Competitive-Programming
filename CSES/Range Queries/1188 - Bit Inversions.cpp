#include "bits/stdc++.h"
using namespace std;

struct Node {
    int mx;
    int mxl, mxr;
    int l, r;
    int n;
};

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0, 0, -1, -1, 1};
    T cmb(T a, T b) {
        int mx = max(a.mx, b.mx);
        if (a.r == b.l)
            mx = max(mx, a.mxr + b.mxl);
        return {mx, a.mxl + (a.mxl == a.n && a.l == b.l ? b.mxl : 0), b.mxr + (b.mxr == b.n && b.r == a.r ? a.mxr : 0), a.l, b.r, a.n + b.n};
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
    void upd(int v, int p = 1, int L = 0, int R = N - 1) {
        if (L == R) {
            seg[p].l ^= 1;
            seg[p].r ^= 1;
        } else {
            int M = (L + R) / 2;
            if (v <= M)
                upd(v, 2 * p, L, M);
            else
                upd(v, 2 * p + 1, M + 1, R);
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

    string s;
    int n;
    cin >> s >> n;
    vector<Node> v(s.length());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0')
            v[i] = {1, 1, 1, 0, 0, 1};
        else
            v[i] = {1, 1, 1, 1, 1, 1};
    }

    Seg<Node, 1 << 18> seg;
    seg.build(v);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        seg.upd(a - 1);

        cout << seg.seg[1].mx << " \n"[i + 1 == n];
    }
}
