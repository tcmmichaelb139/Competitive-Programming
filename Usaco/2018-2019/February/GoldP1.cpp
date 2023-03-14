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
    void upd(int p, T val) {
        for (; p <= n; p += p & -p) v[p] ^= val;
    }
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r, val);
    }
    T query(int k) {
        T sum = 0;
        for (; k; k -= k & -k) sum ^= v[k];
        return sum;
    }
};

const int MAXN = 1e5 + 1;

int h[MAXN], tour[MAXN * 2], in[MAXN], out[MAXN];

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

int n, q;
int val[MAXN];
vector<int> adj[MAXN];
int xors[MAXN];
int st[MAXN], en[MAXN];

int timer = 1, timer2 = 0;

void dfs(int v, int prev) {
    st[v] = timer++;
    xors[v] = xors[prev] ^ val[v];

    in[v] = timer2;
    h[v] = h[prev] + 1;
    tour[timer2++] = v;
    for (auto u : adj[v])
        if (u != prev) {
            dfs(u, v);
            tour[timer2++] = v;
        }

    en[v] = timer++;

    out[v] = timer2;
}

int main() {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    BIT<int> bit;
    bit.init(timer);

    Seg<int> seg;
    seg.init(timer2);

    for (int i = 0; i < timer2; i++)
        seg.upd(i, tour[i]);

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            bit.upd(st[b], en[b], val[b]);
            bit.upd(st[b], en[b], c);
            val[b] = c;
        } else {
            if (seg.query(in[b], in[c]) == -1) swap(b, c);
            cout << (bit.query(st[b]) ^ bit.query(st[c]) ^ xors[b] ^ xors[c] ^ (val[seg.query(in[b], in[c])])) << '\n';
        }
    }
}
