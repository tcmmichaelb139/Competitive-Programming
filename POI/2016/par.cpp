#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n;
vector<int> adj[MAXN];
int dp[MAXN];
int ans;

void dfs(int v, int p) {
    dp[v] = (int)adj[v].size() - 1;
    int mx1 = 0, mx2 = 0;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v] = max(dp[v], dp[u] + (int)adj[v].size() - 2);
        ans = max(ans, dp[u] + (int)adj[v].size() - 1);
        if (mx1 < dp[u])
            mx2 = mx1, mx1 = dp[u];
        else if (mx2 < dp[u])
            mx2 = dp[u];
    }
    if (adj[v].size() >= 2)
        ans = max(ans, mx1 + mx2 + (int)adj[v].size() - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int st = 1;
    for (int i = 2; i <= n; i++)
        if (adj[st].size() < adj[i].size())
            st = i;
    dfs(st, 0);

    cout << max(ans, dp[1]) << '\n';
}
