#include "bits/stdc++.h"
using namespace std;

template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = 0;
    T cmb(T a, T b) { return a + b; }
    T seg[2 * N], lazy[2 * N];
    LazySeg() {
        for (int i = 0; i < 2 * N; i++)
            seg[i] = lazy[i] = ID;
    }
    void push(int p, int L, int R) {
        seg[p] += (R - L + 1) * lazy[p];
        if (L != R) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    void upd(int lo, int hi, T inc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            lazy[p] = inc;
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * p, L, M);
        upd(lo, hi, inc, 2 * p + 1, M + 1, R);
    }
    T query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
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

    LazySeg<long long, 262144> seg;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        seg.upd(i, i, a);
    }

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            long long u;
            cin >> b >> c >> u;
            b--, c--;
            seg.upd(b, c, u);
        } else {
            int b;
            cin >> b;
            b--;
            cout << seg.query(b, b) << '\n';
        }
    }
}
