#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long mx;
    long long mxl;
    long long mxr;
    long long sum;
};

template <class T, int N>
struct Seg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0, 0, 0};
    T cmb(T a, T b) {
        long long mx = max(a.mx, b.mx);
        mx = max(mx, a.mxr + b.mxl);
        long long mxl = max(a.mxl, a.sum + b.mxl);
        long long mxr = max(b.mxr, b.sum + a.mxr);
        long long sum = a.sum + b.sum;
        return {mx, mxl, mxr, sum};
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

    int n, m;
    cin >> n >> m;
    vector<Node> v(n, {0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        cin >> v[i].mx;
        v[i].mxl = max(v[i].mxl, v[i].mx);
        v[i].mxr = max(v[i].mxr, v[i].mx);
        v[i].sum = v[i].mx;
    }

    Seg<Node, 1 << 18> seg;
    seg.build(v);

    for (int i = 0; i < m; i++) {
        int a;
        long long b;
        cin >> a >> b;

        long long mx = max(mx, b);
        seg.upd(a - 1, {mx, mx, mx, b});
        cout << seg.seg[1].mx << '\n';
    }
}
