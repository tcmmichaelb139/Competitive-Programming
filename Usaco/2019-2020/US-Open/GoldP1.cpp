#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
    const T ID = 0;
    T cmb(T a, T b) { return a + b; }
    int N;
    vector<T> seg;
    void init(int _N) {
        for (N = 1; N < _N;) N *= 2;
        seg.assign(2 * N, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val) {
        seg[p += N] += val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(rb, seg[--r]);
        }
        return cmb(ra, rb);
    }
};

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    Seg<long long> seg;
    seg.init(n + 1);

    for (int i = 0; i < n; i++)
        cin >> v[i], seg.upd(v[i], 1);

    vector<long long> num(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        num[v[i]] += seg.query(v[i] + 1, n);
        seg.upd(v[i], -1);
    }
    for (int i = 1; i <= n; i++)
        num[i] += num[i - 1];

    cout << 0 << '\n';
    for (int i = 0; i < n - 1; i++)
        cout << num[i] << '\n';
}
