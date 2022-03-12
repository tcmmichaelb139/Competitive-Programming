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
vector<int> adj[200001];
bool added[200001];

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[n-i-1];
    vector<int> ans(n);
    DSU dsu;
    dsu.init(n+1);
    for (int i = 0; i < n; i++) {
        for (auto j: adj[v[i]]) 
            if (added[j]) {
                dsu.unite(j, v[i]);
            }
        added[v[i]] = true;
        if (dsu.size(v[i]) == i+1) 
            ans[n-i-1] = 1;
        else 
            ans[n-i-1] = 0;
    }
    for (int i = 0; i < n; i++) 
        cout << (ans[i] ? "YES" : "NO") << '\n';
}
