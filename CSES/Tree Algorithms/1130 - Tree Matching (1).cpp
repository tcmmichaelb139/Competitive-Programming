// greedy solution
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 1;

int n;
vector<int> adj[MAXN];
bool done[MAXN];
int ans = 0;

void dfs(int v, int p) {
    for (auto u : adj[v])
        if (u != p) {
            dfs(u, v);
            if (!done[u] && !done[v]) done[u] = done[v] = true, ans++;
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
    cout << ans << '\n';
}
