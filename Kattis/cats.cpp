#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    void init(int n) { v.assign(n, -1); }
    int get(int p) { return v[p] < 0 ? p : v[p] = get(v[p]); }
    bool unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a] > v[b]) swap(a, b);
        v[a] += v[b];
        v[b] = a;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> m >> n;
    vector<pair<int, pair<int, int>>> v(n * (n - 1) / 2);
    for (int i = 0; i < n * (n - 1) / 2; i++)
        cin >> v[i].second.first >> v[i].second.second >> v[i].first;

    sort(begin(v), end(v));

    DSU dsu;

    dsu.init(n * (n - 1) / 2);

    int ans = 0;

    for (auto i : v)
        if (dsu.unite(i.second.first, i.second.second))
            ans += i.first;

    cout << (m - ans >= n ? "yes" : "no") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
