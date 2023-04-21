// dp solution
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n;
vector<int> adj[MAXN];
int dp[MAXN][2];

void dfs(int v, int p) {
    int sum = 0;
    for (auto u : adj[v])
        if (u != p) {
            dfs(u, v);
            sum += max(dp[u][0], dp[u][1]);
        }
    dp[v][0] = max(dp[v][0], sum);
    for (auto u : adj[v]) {
        if (u == p) continue;
        dp[v][1] = max(dp[v][1], dp[u][0] + dp[v][0] - max(dp[u][0], dp[u][1]) + 1);
    }
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
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
