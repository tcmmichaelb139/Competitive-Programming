#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
vector<int> adj[MAXN];
int par[MAXN];
int pre[MAXN];
int mx[MAXN];

void dfs(int v, int start) {
    for (auto u : adj[v]) {
        if (start == n && mx[u] < mx[v] + 1) {
            pre[u] = v;
            mx[u] = mx[v] + 1;
        }
        if (--par[u] == 0)
            dfs(u, start);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == n) continue;
        adj[b].push_back(a);
        par[a]++;
    }
    vector<int> start;
    for (int i = 1; i <= n; i++)
        if (par[i] == 0)
            start.push_back(i);

    for (auto i : start)
        dfs(i, i);

    vector<int> ans;
    for (int i = 1; i != 0; i = pre[i])
        ans.push_back(i);

    if (ans[ans.size() - 1] == n) {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i + 1 == ans.size()];
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
