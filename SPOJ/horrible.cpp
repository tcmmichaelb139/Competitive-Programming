#include "bits/stdc++.h"
using namespace std;

template <class T>
struct BIT {
    vector<T> v;
    int n;
    void init(int _n) {
        n = _n;
        v.resize(n + 1);
    }
    void add(int p, T val) {
        for (; p <= n; p += p & -p) v[p] += val;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    T sum(int k) {
        T sum = 0;
        for (; k; k -= k & -k) sum += v[k];
        return sum;
    }
};

template <class T>
struct RangeBIT {
    BIT<T> bit[2];
    void init(int _n) {
        bit[0].init(_n);
        bit[1].init(_n);
    }
    void upd(int l, int r, T val) {
        bit[0].add(l, val);
        bit[0].add(r + 1, -val);
        bit[1].add(l, val * (l - 1));
        bit[1].add(r + 1, -val * r);
    }
    T sum(int p) { return bit[0].sum(p) * p - bit[1].sum(p); }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    RangeBIT<long long> bit;
    bit.init(n + 1);
    while (q--) {
        int x;
        cin >> x;
        if (x == 0) {
            int l, r;
            long long val;
            cin >> l >> r >> val;
            bit.upd(l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
