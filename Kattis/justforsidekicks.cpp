#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
    const T ID = 0;
    int N;
    vector<T> seg;
    T cmb(T a, T b) { return a + b; }
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

    long long n, q;
    cin >> n >> q;
    vector<long long> v(7);
    for (int i = 1; i <= 6; i++)
        cin >> v[i];

    Seg<long long> s1, s2, s3, s4, s5, s6;
    s1.init(n + 1);
    s2.init(n + 1);
    s3.init(n + 1);
    s4.init(n + 1);
    s5.init(n + 1);
    s6.init(n + 1);

    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            s1.upd(i + 1, 1);
        } else if (s[i] == '2') {
            s2.upd(i + 1, 1);
        } else if (s[i] == '3') {
            s3.upd(i + 1, 1);
        } else if (s[i] == '4') {
            s4.upd(i + 1, 1);
        } else if (s[i] == '5') {
            s5.upd(i + 1, 1);
        } else if (s[i] == '6') {
            s6.upd(i + 1, 1);
        } else
            assert(false);
    }

    for (int i = 0; i < q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            s1.upd(b, 0);
            s2.upd(b, 0);
            s3.upd(b, 0);
            s4.upd(b, 0);
            s5.upd(b, 0);
            s6.upd(b, 0);
            if (c == 1) {
                s1.upd(b, 1);
            } else if (c == 2) {
                s2.upd(b, 1);
            } else if (c == 3) {
                s3.upd(b, 1);
            } else if (c == 4) {
                s4.upd(b, 1);
            } else if (c == 5) {
                s5.upd(b, 1);
            } else if (c == 6) {
                s6.upd(b, 1);
            } else
                assert(false);
        } else if (a == 2) {
            v[b] = c;
        } else {
            long long ans = 0;
            ans += s1.query(b, c) * v[1];
            ans += s2.query(b, c) * v[2];
            ans += s3.query(b, c) * v[3];
            ans += s4.query(b, c) * v[4];
            ans += s5.query(b, c) * v[5];
            ans += s6.query(b, c) * v[6];
            cout << ans << '\n';
        }
    }
}
