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
        seg.assign(N * 2, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val) {
        seg[p += N] += val;
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

int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }

    map<int, int> m;
    int cur = 1;
    for (auto i : s)
        m[i] = cur++;

    Seg<int> segl, segr;
    segl.init(cur + 1);
    segr.init(cur + 1);

    for (int i = 0; i < n; i++)
        segr.upd(m[v[i]], 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = segl.query(m[v[i]] + 1, cur);
        int r = segr.query(m[v[i]] + 1, cur);

        if (l > r) swap(l, r);
        if (l * 2 < r) ans++;

        segl.upd(m[v[i]], 1);
        segr.upd(m[v[i]], -1);
    }
    cout << ans << '\n';
}
