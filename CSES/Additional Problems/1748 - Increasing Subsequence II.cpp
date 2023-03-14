#include "bits/stdc++.h"
using namespace std;

long long MOD = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % MOD; }

template <class T>
struct Seg {
    const T ID = 0;
    T cmb(T a, T b) { return add(a, b); }
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> vals = v;
    sort(begin(vals), end(vals));
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    Seg<long long> seg;
    seg.init(vals.size());

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int ind = lower_bound(begin(vals), end(vals), v[i]) - begin(vals);
        long long q = seg.query(ind + 1, vals.size() - 1);
        ans = add(ans, q + 1);
        seg.upd(ind, q + 1);
    }
    cout << ans << '\n';
}
