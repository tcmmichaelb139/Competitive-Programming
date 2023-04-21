#include "bits/stdc++.h"
using namespace std;

template <class T>
struct SparseTable {
    int level(int x) { return 31 - __builtin_clz(x); }
    vector<T> v;
    vector<vector<int>> jmp;
    int cmb(int a, int b) {
        return v[a] == v[b] ? min(a, b) : (v[a] < v[b] ? a : b);
    }
    void init(const vector<T>& _v) {
        v = _v;
        jmp = {vector<int>(size(v))};
        iota(begin(jmp[0]), end(jmp[0]), 0);
        for (int j = 1; 1 << j <= size(v); ++j) {
            jmp.push_back(vector<int>(size(v) - (1 << j) + 1));
            for (int i = 0; i < size(jmp[j]); i++)
                jmp[j][i] = cmb(jmp[j - 1][i], jmp[j - 1][i + (1 << (j - 1))]);
        }
    }
    int index(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return cmb(jmp[d][l], jmp[d][r - (1 << d) + 1]);
    }
    T query(int l, int r) { return v[index(l, r)]; }
};

const int MAXN = 1e5 + 1;

int n, m;
int type[MAXN];
vector<int> adj[MAXN];
vector<int> cur[MAXN];
vector<pair<int, int>> t[MAXN];
int in[MAXN];
vector<int> h;
vector<int> h_rev;

int timer = 0;

void dfs(int v, int p, int hei) {
    cur[type[v]].push_back(v);
    t[type[v]].push_back({timer, v});

    in[v] = timer++;
    h.push_back(hei);
    h_rev.push_back(v);

    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, hei + 1);

        timer++;
        h.push_back(hei);
        h_rev.push_back(v);
    }

    cur[type[v]].pop_back();
    t[type[v]].push_back({timer, (size(cur[type[v]]) ? cur[type[v]].back() : 0)});
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> type[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    SparseTable<int> lca;
    lca.init(h);

    auto last = [&](int a, int b) {
        auto it = upper_bound(begin(t[b]), end(t[b]), make_pair(in[a], (int)1e9 + 7));
        if (it == begin(t[b])) return 0;
        return prev(it)->second;
    };

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int l = h_rev[lca.index(min(in[a], in[b]), max(in[a], in[b]))];

        int test = last(a, c);
        if (test && h[in[test]] >= h[in[l]]) {
            cout << 1;
            continue;
        }
        test = last(b, c);
        if (test && h[in[test]] >= h[in[l]]) {
            cout << 1;
            continue;
        }

        cout << 0;
    }
    cout << '\n';
}
