#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    void init(int N) { v.assign(N, -1); }
    int get(int p) { return v[p] < 0 ? p : get(v[p]); }
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto dist = [](pair<long long, long long> a, pair<long long, long long> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    };

    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(begin(v), end(v));

    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(i + 50, n); j++)
            edges.push_back({dist(v[i], v[j]), {i, j}});
    }

    sort(begin(edges), end(edges));

    DSU dsu;
    dsu.init(n);

    long long ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (dsu.unite(edges[i].second.first, edges[i].second.second))
            ans += edges[i].first;
    }
    cout << ans << '\n';
}
