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
    auto square = [](const double a) { return a * a; };
    auto dist = [&](const pair<double, double> a, const pair<double, double> b) {
        return sqrt(square(a.first - b.first) + square(a.second - b.second));
    };

    int n;
    cin >> n;
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    vector<pair<int, int>> con(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            con.push_back({i, j});

    sort(begin(con), end(con), [&](const pair<int, int> a, const pair<int, int> b) {
        return dist(v[a.first], v[a.second]) < dist(v[b.first], v[b.second]);
    });

    DSU dsu;
    dsu.init(n);

    double ans = 0;
    for (auto i : con)
        if (dsu.unite(i.first, i.second))
            ans += dist(v[i.first], v[i.second]);

    cout << setprecision(12) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
