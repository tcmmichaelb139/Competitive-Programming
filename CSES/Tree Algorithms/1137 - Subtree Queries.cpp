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

const int MAXN = 2e5 + 1;

int n, q;
long long ar[MAXN];
vector<int> adj[MAXN];
int timer = 0;
int in[MAXN];
int out[MAXN];
Seg<long long> seg;

void dfs(int v, int prev) {
    seg.upd(timer, ar[v]);
    in[v] = timer++;
    for (auto u : adj[v])
        if (u != prev) dfs(u, v);
    out[v] = timer - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    seg.init(n + 1);

    dfs(1, -1);

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            seg.upd(in[b], c);
        } else {
            int b;
            cin >> b;
            cout << seg.query(in[b], out[b]) << '\n';
        }
    }
}
