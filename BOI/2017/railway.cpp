#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100'001, MS = 18;

int n, m, k;
vector<int> adj[MAXN];
int jmp[MS][MAXN];
int tin[MAXN];
int h[MAXN];
int pref[MAXN];
int timer = 0;
map<pair<int, int>, int> ind;
int sol[MAXN];

void dfs1(int v, int p, int hei) {
    h[v] = hei;
    jmp[0][v] = p;
    tin[v] = timer++;
    for (auto u : adj[v])
        if (u != p)
            dfs1(u, v, hei + 1);
}

void dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs2(u, v);
        sol[ind[{min(v, u), max(v, u)}]] = pref[u];
        pref[v] += pref[u];
    }
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    int diff = h[a] - h[b];
    for (int i = MS - 1; i >= 0; i--)
        if (diff & (1 << i))
            a = jmp[i][a];
    if (a != b) {
        for (int i = MS - 1; i >= 0; i--) {
            if (jmp[i][a] != jmp[i][b]) {
                a = jmp[i][a];
                b = jmp[i][b];
            }
        }
        a = jmp[0][a];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ind[{min(a, b), max(a, b)}] = i;
    }

    dfs1(1, 0, 0);

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        vector<int> v(s);
        for (int j = 0; j < s; j++)
            cin >> v[j];

        sort(begin(v), end(v), [&](int a, int b) { return tin[a] < tin[b]; });

        v.push_back(v[0]);
        for (int j = 0; j < s; j++) {
            int l = lca(v[j], v[j + 1]);
            pref[v[j]]++;
            pref[v[j + 1]]++;
            pref[l] -= 2;
        }
    }

    dfs2(1, 0);

    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
        if (sol[i] >= 2 * k)
            ans.push_back(i + 1);
    cout << size(ans) << '\n';
    for (int i = 0; i < size(ans); i++)
        cout << ans[i] << " \n"[i + 1 == size(ans)];
}
