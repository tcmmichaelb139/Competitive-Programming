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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using IndSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Seg<int> seg;
    seg.init(n + 1);

    int ind = -1;
    for (ind = n - 1; ind >= 0; ind--) {
        if (seg.query(0, v[ind] - 1))
            break;
        seg.upd(v[ind], 1);
    }

    ind++;

    IndSet<int> ans;
    for (int i = ind; i < n; i++)
        ans.insert(v[i]);

    cout << ind << '\n';
    for (int i = 0; i < ind; i++) {
        cout << ans.order_of_key(v[i]) + ind - i - 1 << " \n"[i + 1 == ind];
        ans.insert(v[i]);
    }
}
