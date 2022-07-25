#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

vector<int> adj[MAXN];
bool vis[MAXN];
int par[MAXN];
int start = 0;
bool done = false;
vector<int> ans;

void topo(int v) {
    for (auto u : adj[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        if (--par[u] == 0) topo(u);
    }
}

void getAns(int v) {
    if (done) return;
    for (auto u : adj[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        if (u == start) done = true;
        getAns(u);
    }
    if (done) {
        ans.push_back(v);
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        par[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (par[i]) continue;
        if (vis[i]) continue;
        vis[i] = true;
        topo(i);
    }
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (par[i]) {
            start = i;
            getAns(i);
            if (ans.size()) {
                reverse(begin(ans), end(ans));
                ans.push_back(i);
                break;
            }
        }
    }
    if (ans.size()) {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i + 1 == ans.size()];
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
