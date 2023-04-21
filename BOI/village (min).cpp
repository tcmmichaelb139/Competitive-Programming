#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n;
vector<int> adj[MAXN];
bool done[MAXN];
int ans = 0;
int sol[MAXN];

void dfs(int v, int p) {
    int num = 0;
    vector<int> pos;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        num += !done[u];
        if (!done[u])
            pos.push_back(u);
    }
    if (num == 0) return;
    ans += num * 2;
    pos.push_back(v);
    for (int i = 0; i < pos.size(); i++)
        sol[pos[i]] = pos[(i + 1) % pos.size()], done[pos[i]] = true;
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

    if (n == 2) {
        cout << 2 << '\n'
             << "2 1\n";
        return 0;
    }

    dfs(1, 0);

    if (sol[1] == 0) {
        sol[1] = sol[adj[1][0]];
        sol[adj[1][0]] = 1;
        ans += 2;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << sol[i] << " \n"[i == n];
}
