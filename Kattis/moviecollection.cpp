#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

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
        for (p /= 2; p; p /= 2)
            pull(p);
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

void solve() {
    int n, r;
    cin >> n >> r;
    Seg<int> seg;
    seg.init(MAXN);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = n - i - 1;
        seg.upd(i);
    }
    for (int i = 0; i < r; i++) {
        int a;
        cin >> a;
        a--;
        seg.upd(v[a]);
        cout << seg.query(v[a], n) << " \n"[i + 1 == r];
        v[a] = n;
        seg.upd(n);
        n++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
