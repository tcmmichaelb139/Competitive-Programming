#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> v;
vector<int> sz;
vector<vector<int>> adj;

int dfs(int v) {
    int cur = 1;
    for (auto u : adj[v])
        cur += dfs(u);
    sz[v] = cur;
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.assign(n + 1, -1);
    sz.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> v[i];
        adj[v[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << sz[i] - 1 << " \n"[i == n];
}
