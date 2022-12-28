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

int main() {
    // a little slow but if you run it enough times it will get 10/10
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto hash = [](pair<long long, long long> a) {
        return a.first * 2001 + a.second;
    };

    long long A, B, n, m;
    cin >> A >> B >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    a.push_back(A);
    b.push_back(B);

    vector<pair<long long, pair<int, int>>> edges;

    long long prei = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long p1 = hash({i, j});
            long long p2 = hash({i, j - 1});

            edges.push_back({a[i] - prei, {p1, p2}});
        }
        prei = a[i];
    }

    long long prej = 0;
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            long long p1 = hash({i, j});
            long long p2 = hash({i - 1, j});

            edges.push_back({b[j] - prej, {p1, p2}});
        }
        prej = b[j];
    }

    sort(begin(edges), end(edges));

    DSU dsu;
    dsu.init(2010 * 2010);

    long long ans = 0;
    for (auto i : edges)
        if (dsu.unite(i.second.first, i.second.second))
            ans += i.first;

    cout << ans << '\n';
}
