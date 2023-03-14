#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n, q;
int timer = 0;
vector<int> adj[MAXN];
int in[MAXN];
vector<int> vals;

template <class T>
struct Seg {
    const T ID = -1;
    T cmb(T a, T b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return in[a] < in[b] ? a : b;
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

void dfs(int v, int prev) {
    in[v] = timer;
    vals.push_back(v);
    timer++;
    for (auto u : adj[v])
        if (u != prev) {
            dfs(u, v);
            vals.push_back(v);
            timer++;
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, -1);

    Seg<int> seg;
    seg.init(timer);
    for (int i = 0; i < timer; i++)
        seg.upd(i, vals[i]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (in[a] > in[b]) swap(a, b);
        cout << seg.query(in[a], in[b]) << '\n';
    }
}
