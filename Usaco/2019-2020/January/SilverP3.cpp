#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> v;
    void init(int n) { v = vector<int>(n, -1); }
    int get(int a) { return (v[a] < 0 ? a : get(v[a])); }
    int size(int a) { return -v[get(a)]; }
    bool unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a] > v[b]) swap(a, b);
        v[a] += v[b]; v[b] = a;
        return true;
    }
};

int n, m;
int cor = 0;
vector<int> v;

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    vector<int> v;
    vector<int> corv(n+1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
        if (a == i+1)
            cor++, corv[i+1] = true;
    }
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    sort(rbegin(edge), rend(edge));
    DSU dsu;
    dsu.init(n+1);
    if (cor == n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < m; i++) {
        dsu.unite(edge[i].second.first, edge[i].second.second);
        if (corv[edge[i].second.first])
            cor--, corv[edge[i].second.first] = false;
        if (corv[edge[i].second.second])
            cor--, corv[edge[i].second.second] = false;
        if (dsu.size(edge[i].second.first)+cor == n) {
            cout << edge[i].first << '\n';
            return 0;
        }
    }
}
