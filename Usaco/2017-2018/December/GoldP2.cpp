#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;
const long long MOD = 1e9 + 7;

int n, k;
vector<int> adj[MAXN];
long long dp[MAXN][4];
long long colored[MAXN];
bool vis[MAXN];

const long long add(long long a, long long b) { return (a + b) % MOD; }
const long long mult(long long a, long long b) { return a * b % MOD; }

void dfs(int v) {
    if (colored[v]) {
        dp[v][1] = dp[v][2] = dp[v][3] = 0;
        dp[v][colored[v]] = 1;
    } else {
        dp[v][1] = dp[v][2] = dp[v][3] = 1;
    }
    for (auto u : adj[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        dfs(u);
        vector<int> cur(4, 0);
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (i != j)
                    cur[i] = add(cur[i], dp[u][j]);
        for (int i = 1; i <= 3; i++)
            dp[v][i] = mult(dp[v][i], cur[i]);
    }
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        colored[a] = b;
    }
    vis[1] = true;
    dfs(1);
    cout << add(add(dp[1][1], dp[1][2]), dp[1][3]) << '\n';
}
