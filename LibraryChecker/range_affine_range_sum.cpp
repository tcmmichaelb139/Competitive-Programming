#include "bits/stdc++.h"
using namespace std;

const long long MOD = 998'244'353;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

struct Node {
    long long val;
    long long lzProd;
    long long lzAdd;
};

template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 1, 0};
    long long cmb(long long a, long long b) { return add(a, b); }
    T seg[2 * N];
    void push(int p, int L, int R) {
        seg[p].val = mult(seg[p].val, seg[p].lzProd);
        seg[p].val = add(seg[p].val, (R - L + 1) * seg[p].lzAdd);
        if (L != R) {
            seg[2 * p].lzProd = mult(seg[p].lzProd, seg[2 * p].lzProd);
            seg[2 * p].lzAdd = add(seg[p].lzAdd, mult(seg[2 * p].lzAdd, seg[p].lzProd));
            seg[2 * p + 1].lzProd = mult(seg[p].lzProd, seg[2 * p + 1].lzProd);
            seg[2 * p + 1].lzAdd = add(seg[p].lzAdd, mult(seg[2 * p + 1].lzAdd, seg[p].lzProd));
        }
        seg[p].lzProd = 1;
        seg[p].lzAdd = 0;
    }
    void pull(int p) { seg[p].val = cmb(seg[2 * p].val, seg[2 * p + 1].val); }
    void build(vector<long long> &v, int p = 1, int L = 0, int R = N - 1) {
        seg[p].lzAdd = ID.lzAdd;
        seg[p].lzProd = ID.lzProd;
        if (L == R) {
            if (size(v) > L)
                seg[p].val = v[L];
        } else {
            int M = (L + R) / 2;
            build(v, 2 * p, L, M);
            build(v, 2 * p + 1, M + 1, R);
            pull(p);
        }
    }
    void upd(int lo, int hi, long long incb, long long incc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            seg[p].lzProd = mult(seg[p].lzProd, incb);
            seg[p].lzAdd = add(incc, mult(seg[p].lzAdd, incb));
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, incb, incc, 2 * p, L, M);
        upd(lo, hi, incb, incc, 2 * p + 1, M + 1, R);
        pull(p);
    }
    long long query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return ID.val;
        if (lo <= L && R <= hi) return seg[p].val;
        int M = (L + R) / 2;
        return cmb(query(lo, hi, 2 * p, L, M), query(lo, hi, 2 * p + 1, M + 1, R));
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    LazySeg<Node, 1 << 19> seg;
    seg.build(v);

    while (q--) {
        int a;
        cin >> a;
        if (a == 0) {
            int l, r;
            long long b, c;
            cin >> l >> r >> b >> c;
            seg.upd(l, r - 1, b, c);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r - 1) << '\n';
        }
    }
}
