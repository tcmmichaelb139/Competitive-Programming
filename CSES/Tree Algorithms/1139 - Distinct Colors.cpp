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
    void add(int p, T val) {
        for (; p <= n; p += p & -p)
            v[p] += val;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    T sum(int k) {
        T sum = 0;
        for (; k; k -= k & -k) sum += v[k];
        return sum;
    }
};

const int MAXN = 2e5 + 1;

int n;
int c[MAXN];
vector<int> adj[MAXN];
int st[MAXN], en[MAXN];
int timer = 1;

void dfs(int v, int prev) {
    st[v] = timer;
    for (auto u : adj[v])
        if (u != prev)
            dfs(u, v);
    en[timer++] = v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    BIT<int> bit;
    bit.init(n + 1);

    map<int, int> prev;

    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        if (prev.find(c[en[i]]) != prev.end())
            bit.add(prev[c[en[i]]], -1);

        prev[c[en[i]]] = i;

        bit.add(i, 1);

        ans[en[i]] = bit.sum(st[en[i]], i);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
