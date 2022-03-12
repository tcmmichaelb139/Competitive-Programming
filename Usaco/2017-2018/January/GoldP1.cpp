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

int n, q; 
vector<pair<int, pair<int, int>>> v;
vector<pair<pair<int, int>, int>> x;

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(rbegin(v), rend(v));
    DSU dsu;
    dsu.init(n+1);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        x.push_back({{a, b}, i});
    }
    sort(rbegin(x), rend(x));
    vector<int> ans(q);
    int j = 0;
    for (int i = 0; i < q; i++) {
        while (j < n) {
            if (v[j].first < x[i].first.first) break;
            dsu.unite(v[j].second.first, v[j].second.second);
            j++;
        }
        ans[x[i].second] = dsu.size(x[i].first.second);
    }
    for (int i = 0; i < q; i++) 
        cout << ans[i]-1 << '\n';
}
