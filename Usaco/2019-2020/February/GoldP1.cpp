#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, m, c;
int degree[MAXN];
vector<pair<int, int>> adj[MAXN];
int worst[MAXN];

void dfs(int v) {
    for (auto u : adj[v]) {
        worst[u.first] = max(worst[u.first], worst[v] + u.second);
        if (!(--degree[u.first]))
            dfs(u.first);
    }
}

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        cin >> worst[i];

    for (int i = 0; i < c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        degree[b]++;
    }
    vector<int> start;
    for (int i = 1; i <= n; i++)
        if (!degree[i])
            start.push_back(i);
    for (auto i : start)
        dfs(i);

    for (int i = 1; i <= n; i++)
        cout << worst[i] << '\n';
}
