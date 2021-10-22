#include <bits/stdc++.h>
using namespace std;

template<class T> struct Seg {
    const T ID = 1e9; 
    T cmb(T a, T b) { return min(a, b); } //change this
    int n; vector<T> seg;
    void init(int _n) {
        for (n = 1; n < _n; ) n *= 2;
        seg.assign(2*n, ID);
    }
    void pull(int p) {
        seg[p] = cmb(seg[2*p], seg[2*p+1]);
    }
    void upd(int p, T val) {
        seg[p += n] = val; 
        for (p /= 2; p; p/= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = cmb(ra, seg[l++]);
            if (r&1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, q;
    cin >> n >> q;
    Seg<int> s; s.init(n+1);
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        s.upd(i, e);
    }
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            s.upd(b, c);
        }
        else {
            cout << s.query(b, c) << '\n';
        }
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

