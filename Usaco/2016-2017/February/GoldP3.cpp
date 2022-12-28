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
    void upd(int p) {
        seg[p += N] ^= 1;
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
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<int> m(n, -1);

    for (int i = 0; i < 2 * n; i++)
        if (m[v[i]] == -1)
            m[v[i]] = i;

    Seg<int> seg;
    seg.init(2 * n);

    int ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (seg.query(m[v[i]], m[v[i]]))
            ans += seg.query(m[v[i]] + 1, i - 1);

        seg.upd(m[v[i]]);
    }
    cout << ans << '\n';
}
