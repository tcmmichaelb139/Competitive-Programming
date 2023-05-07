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
        seg[p += N] = val;
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<pair<int, int>>> que(n);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        que[b].push_back({a, i});
    }

    map<int, int> pre;

    vector<int> ans(q);

    Seg<int> seg;
    seg.init(n);

    for (int i = 0; i < n; i++) {
        if (pre.find(v[i]) != pre.end())
            seg.upd(pre[v[i]], 0);
        pre[v[i]] = i;
        seg.upd(i, 1);
        for (auto j : que[i]) {
            ans[j.second] = seg.query(j.first, i);
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}
