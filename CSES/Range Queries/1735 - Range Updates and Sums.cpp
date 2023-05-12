#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long val;
    long long lzAdd;
    long long lzSet;
};

template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0, 0};
    T seg[2 * N];
    void push(int p, int L, int R) {
        if (seg[p].lzSet != 0) {
            seg[p].val = (R - L + 1) * seg[p].lzSet;
            if (L != R) {
                seg[2 * p].lzSet = seg[p].lzSet;
                seg[2 * p + 1].lzSet = seg[p].lzSet;
                seg[2 * p].lzAdd = seg[2 * p + 1].lzAdd = 0;
            }
            seg[p].lzAdd = seg[p].lzSet = 0;
        } else if (seg[p].lzAdd != 0) {
            seg[p].val += (R - L + 1) * seg[p].lzAdd;
            if (L != R) {
                if (seg[2 * p].lzSet == 0)
                    seg[2 * p].lzAdd += seg[p].lzAdd;
                else {
                    seg[2 * p].lzSet += seg[p].lzAdd;
                    seg[2 * p].lzAdd = 0;
                }
                if (seg[2 * p + 1].lzSet == 0)
                    seg[2 * p + 1].lzAdd += seg[p].lzAdd;
                else {
                    seg[2 * p + 1].lzSet += seg[p].lzAdd;
                    seg[2 * p + 1].lzAdd = 0;
                }
            }
            seg[p].lzAdd = 0;
        }
    }
    void pull(int p) { seg[p].val = seg[2 * p].val + seg[2 * p + 1].val; }
    void build(vector<long long> &v, int p = 1, int L = 0, int R = N - 1) {
        seg[p].lzAdd = seg[p].lzSet = 0;
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
    void upd(int lo, int hi, long long inc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            seg[p].lzAdd += inc;
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * p, L, M);
        upd(lo, hi, inc, 2 * p + 1, M + 1, R);
        pull(p);
    }
    void set(int lo, int hi, long long inc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            seg[p].lzSet = inc;
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        set(lo, hi, inc, 2 * p, L, M);
        set(lo, hi, inc, 2 * p + 1, M + 1, R);
        pull(p);
    }
    long long query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return seg[p].val;
        int M = (L + R) / 2;
        return query(lo, hi, 2 * p, L, M) + query(lo, hi, 2 * p + 1, M + 1, R);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LazySeg<Node, 1 << 18> seg;
    seg.build(v);

    for (int i = 0; i < q; i++) {
        int j;
        cin >> j;
        if (j == 1) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            a--, b--;
            seg.upd(a, b, c);
        } else if (j == 2) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            a--, b--;
            seg.set(a, b, c);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << seg.query(a, b) << '\n';
        }
    }
}
