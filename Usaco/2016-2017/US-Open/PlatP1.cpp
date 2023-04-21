#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

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

int n;
vector<int> adj[MAXN];
int st[MAXN], en[MAXN];
int timer = 0;

void dfs(int v, int p) {
    st[v] = timer++;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    en[v] = timer - 1;
}

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> prof(n);
    for (int i = 0; i < n; i++) {
        cin >> prof[i].first, prof[i].second = i + 1;
    }
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0);

    Seg<int> seg;
    seg.init(n + 1);

    sort(rbegin(prof), rend(prof));

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        ans[prof[i].second] = seg.query(st[prof[i].second], en[prof[i].second]);

        seg.upd(st[prof[i].second], 1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
