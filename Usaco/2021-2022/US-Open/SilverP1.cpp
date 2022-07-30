#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> v;
    void init(int N) { v = vector<int>(N, -1); }
    int get(int x) { return v[x] < 0 ? x : get(v[x]); }
    bool same_set(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -v[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (v[x] > v[y]) swap(x, y);
        v[x] += v[y], v[y] = x;
        return true;
    }
};

int n;
vector<pair<int, long long>> v;
long long ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<pair<int, pair<int, int>>> edge(n);
    for (int i = 0; i < n; i++) {
        edge[i] = {v[i].second, {i, v[i].first - 1}};
    }
    sort(rbegin(edge), rend(edge));
    DSU dsu;
    dsu.init(n + 1);
    for (int i = 0; i < n; i++) {
        if (dsu.unite(edge[i].second.first, edge[i].second.second))
            ans += edge[i].first;
    }
    cout << ans << '\n';
}
