#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long sum;
    long long mn;
    long long lzAdd;
};

template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, (int)1e9, 0};
    T seg[2 * N];
    LazySeg() {
        for (int i = 0; i < 2 * N; i++)
            seg[i] = ID;
    }
    void push(int p, int L, int R) {
        seg[p].sum += (R - L + 1) * seg[p].lzAdd;
        seg[p].mn += seg[p].lzAdd;
        if (L != R) {
            seg[2 * p].lzAdd += seg[p].lzAdd;
            seg[2 * p + 1].lzAdd += seg[p].lzAdd;
        }
        seg[p].lzAdd = 0;
    }
    void pull(int p) {
        seg[p].sum = seg[2 * p].sum + seg[2 * p + 1].sum;
        seg[p].mn = min(seg[2 * p].mn, seg[2 * p + 1].mn);
    }
    void build(vector<long long> &v, int p = 1, int L = 0, int R = N - 1) {
        seg[p].lzAdd = ID.lzAdd;
        if (L == R) {
            if (size(v) > L)
                seg[p].sum = seg[p].mn = v[L];
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
            seg[p].lzAdd = inc;
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * p, L, M);
        upd(lo, hi, inc, 2 * p + 1, M + 1, R);
        pull(p);
    }
    long long sumQuery(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return ID.sum;
        if (lo <= L && R <= hi) return seg[p].sum;
        int M = (L + R) / 2;
        return sumQuery(lo, hi, 2 * p, L, M) + sumQuery(lo, hi, 2 * p + 1, M + 1, R);
    }
    long long minQuery(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return ID.mn;
        if (lo <= L && R <= hi) return seg[p].mn;
        int M = (L + R) / 2;
        return min(minQuery(lo, hi, 2 * p, L, M), minQuery(lo, hi, 2 * p + 1, M + 1, R));
    }
};

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    LazySeg<Node, 1 << 18> seg;
    seg.build(v);

    while (q--) {
        char p;
        cin >> p;
        if (p == 'M') {
            int a, b;
            cin >> a >> b;
            cout << seg.minQuery(a, b) << '\n';
        } else if (p == 'P') {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            seg.upd(a, b, c);
        } else if (p == 'S') {
            int a, b;
            cin >> a >> b;
            cout << seg.sumQuery(a, b) << '\n';
        } else
            assert(false);
    }
}
