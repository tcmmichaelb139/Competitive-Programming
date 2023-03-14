#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n, q;
vector<int> adj[MAXN];
int timer;
int in[MAXN * 2];
int h[MAXN * 2];

template <class T>
struct Seg {
    const T ID = -1;
    T cmb(T a, T b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return (h[a] < h[b] ? a : b);
    }
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

void dfs(int v, int prev, int ht = 0) {
    in[v] = timer;
    h[timer++] = ht;
    for (auto u : adj[v]) {
        if (u == prev) continue;
        dfs(u, v, ht + 1);
        h[timer++] = ht;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    Seg<int> seg;
    seg.init(timer);
    for (int i = 0; i < timer; i++)
        seg.upd(i, i);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (in[a] > in[b]) swap(a, b);
        int mn = seg.query(in[a], in[b]);
        cout << h[in[a]] - h[mn] + h[in[b]] - h[mn] << '\n';
    }
}
