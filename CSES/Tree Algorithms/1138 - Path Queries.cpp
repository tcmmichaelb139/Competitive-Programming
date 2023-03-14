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
        for (; p <= n; p += p & -p) v[p] += val;
    }
    void add(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }
    T sum(int k) {
        T sum = 0;
        for (; k; k -= k & -k) sum += v[k];
        return sum;
    }
};

const int MAXN = 2e5 + 1;

int n, q;
long long val[MAXN];
vector<int> adj[MAXN];
int st[MAXN];
int en[MAXN];
int timer = 1;
long long sum[MAXN];

void dfs(int v, int prev) {
    st[v] = timer;
    sum[v] = sum[prev] + val[v];
    for (auto u : adj[v])
        if (u != prev)
            dfs(u, v);
    en[v] = timer++;
}

int main() {
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

    BIT<long long> bit;
    bit.init(n + 1);

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            long long a, b;
            cin >> a >> b;
            bit.add(st[a], en[a], b - val[a]);
            val[a] = b;
        } else {
            int a;
            cin >> a;
            cout << bit.sum(en[a]) + sum[a] << '\n';
        }
    }
}
