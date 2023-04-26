#include "bits/stdc++.h"
using namespace std;

const int MAXN = 50001, MS = 18;

int n, k;
vector<int> adj[MAXN];
int jmp[MS][MAXN];
int h[MAXN];
int prefa[MAXN], prefs[MAXN], prefd[MAXN];
int ans[MAXN];

void dfs(int v, int p, int hei) {
    jmp[0][v] = p;
    h[v] = hei;
    for (auto u : adj[v])
        if (u != p)
            dfs(u, v, hei + 1);
}

void dfs1(int v, int p) {
    int pa = 0;
    for (auto u : adj[v])
        if (u != p) {
            dfs1(u, v);
            prefs[v] += prefs[u];
            pa += prefa[u];
        }
    ans[v] = prefs[v] - pa - prefd[v];
    prefa[v] += pa;
}

int main() {
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    auto jumpK = [&](int start, int dist) {
        for (int i = 0; i < MS; i++)
            if (dist & (1 << i))
                start = jmp[i][start];
        return start;
    };

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        if (h[a] < h[b]) swap(a, b);

        int dist = h[a] - h[b];

        int lca = jumpK(a, dist);

        if (lca != b) {
            int jb = b;

            for (int j = MS - 1; j >= 0; j--)
                if (jmp[j][jb] != jmp[j][lca]) {
                    jb = jmp[j][jb];
                    lca = jmp[j][lca];
                }

            lca = jmp[0][lca];

            prefa[lca] += 2;
            prefd[lca]++;
            prefs[a]++;
            prefs[b]++;
        } else {
            prefa[lca]++;
            prefs[a]++;
        }
    }
    dfs1(1, 0);

    int ret = 0;

    for (int i = 1; i <= n; i++)
        ret = max(ret, ans[i]);

    cout << ret << '\n';
}
