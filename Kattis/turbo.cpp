#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
    const T ID = 0;
    T cmb(T a, T b) { return a + b; }
    int N;
    vector<T> seg;
    void init(int _N) {
        for (N = 1; N < _N;)
            N *= 2;
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

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> order;

    Seg<int> seg;
    seg.init(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a - 1] = i;
        seg.upd(i, 1);
        if (i == n - i - 1) {
            order.push_back(i);
        } else if (i < n - i - 1) {
            order.push_back(i);
            order.push_back(n - i - 1);
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int ind = v[order[i]];
        seg.upd(ind, 0);
        if (order[i] < n / 2) {
            cout << seg.query(order[i] - l, ind) << '\n';
            l++;
        } else {
            cout << seg.query(ind, order[i] + r) << '\n';
            r++;
        }
    }
}
