#include "bits/stdc++.h"
using namespace std;

struct Node {
    int n;
    pair<int, int> l1, l2;
    pair<int, int> r1, r2;
    int mx;
    int dist;
};

int distSaved(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return abs(a.first - b.first) + abs(a.second - b.second) + abs(b.first - c.first) + abs(b.second - c.second) - abs(a.first - c.first) - abs(a.second - c.second);
}

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {(int)-1e9, {(int)-1e9, (int)-1e9}, {(int)-1e9, (int)-1e9}, {(int)-1e9, (int)-1e9}, {(int)-1e9, (int)-1e9}, (int)-1e9, (int)-1e9};
    T cmb(T a, T b) {
        if (a.n == (int)-1e9) return b;
        if (b.n == (int)-1e9) return a;
        if (a.n == 1 && b.n == 1) {
            return {2, a.l1, b.r1, b.r1, a.l1, 0, dist(a.l1, b.r1)};
        } else if (a.n == 1 && b.n == 2) {
            return {
                3,
                a.l1,
                b.r2,
                b.r1,
                b.r2,
                distSaved(a.l1, b.r2, b.r1),
                dist(a.r1, b.l1) + b.dist};
        } else if (a.n == 2 && b.n == 1) {
            return {
                3,
                a.l1,
                a.l2,
                b.r1,
                a.l2,
                distSaved(a.l1, a.l2, b.r1),
                dist(a.r1, b.l1) + a.dist};
        } else {
            return {
                a.n + b.n,
                a.l1,
                a.l2,
                b.r1,
                b.r2,
                max(max(a.mx, b.mx), max(distSaved(a.r2, a.r1, b.l1), distSaved(a.r1, b.l1, b.l2))),
                dist(a.r1, b.l1) + a.dist + b.dist};
        }
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
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {1, {a, b}, {a, b}, {a, b}, {a, b}, 0, 0};
    }

    Seg<Node, 1 << 17> seg;
    seg.build(v);

    while (q--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int a, b;
            cin >> a >> b;
            Node p = seg.query(a - 1, b - 1);
            cout << p.dist - p.mx << '\n';
        } else {
            int i, x, y;
            cin >> i >> x >> y;
            seg.upd(i - 1, {1, {x, y}, {x, y}, {x, y}, {x, y}, 0, 0});
        }
    }
}
