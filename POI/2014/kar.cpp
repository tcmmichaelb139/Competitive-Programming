#include "bits/stdc++.h"
using namespace std;

struct Node {
    int o[2];
    int l[2], r[2];
};

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {{1, 1}, {(int)1e9, (int)1e9}, {(int)1e9, (int)1e9}};
    T cmb(T a, T b) {
        Node r = {{0, 0}, {0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (a.o[i] && b.o[j] && a.r[i] <= b.l[j])
                    if (!r.o[i] || r.r[i] > b.r[j])
                        r.o[i] = 1, r.l[i] = a.l[i], r.r[i] = b.r[j];
        return r;
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
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {{1, 1}, {a, b}, {a, b}};
    }
    Seg<Node, 1 << 18> seg;
    seg.build(v);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--, b--;
        seg.upd(a, v[b]);
        seg.upd(b, v[a]);
        swap(v[a], v[b]);

        if (seg.seg[1].o[0] || seg.seg[1].o[1])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}
