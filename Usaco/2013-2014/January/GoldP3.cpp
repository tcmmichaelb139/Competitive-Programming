#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    vector<long long> num;
    void init(int n) {
        v = vector<int>(n, -1);
        num = vector<long long>(n, 0);
    }
    int sameSet(int a, int b) { return get(a) == get(b); }
    int get(int a) { return v[a] < 0 ? a : v[a] = get(v[a]); }
    int size(int a) { return -v[get(a)]; }
    int unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a] > v[b]) swap(a, b);
        v[a] += v[b];
        v[b] = a;
        num[a] += num[b];
        num[b] = 0;
        return true;
    }
};

int main() {
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    auto cto = [&](int a, int b) { return a * m + b; };

    vector<int> v(n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[cto(i, j)];

    DSU dsu;
    dsu.init(n * m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a)
                dsu.num[cto(i, j)] = 1;
        }

    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n)
                edges.push_back({abs(v[cto(i, j)] - v[cto(i + 1, j)]), {cto(i, j), cto(i + 1, j)}});
            if (j + 1 < m)
                edges.push_back({abs(v[cto(i, j)] - v[cto(i, j + 1)]), {cto(i, j), cto(i, j + 1)}});
        }
    }

    sort(begin(edges), end(edges));

    long long ans = 0;

    for (int i = 0; i < edges.size(); i++) {
        dsu.unite(edges[i].second.first, edges[i].second.second);
        if (dsu.size(edges[i].second.first) < t) continue;

        ans += dsu.num[dsu.get(edges[i].second.first)] * edges[i].first;

        dsu.num[dsu.get(edges[i].second.first)] = 0;
    }
    cout << ans << '\n';
}
