#include "bits/stdc++.h"
using namespace std;

const int MAXN = 50001, MS = 18;

int n, m;
vector<int> adj[MAXN];
int jmp[MS][MAXN];
int h[MAXN];
map<pair<int, int>, int> ans;

vector<int> rem[MAXN];
vector<int> add[MAXN];

void dfs(int v, int p, int d) {
    jmp[0][v] = p;
    h[v] = d;
    for (auto u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}

multiset<int> dfs2(int v, int p) {
    multiset<int> cur;
    for (auto u : adj[v])
        if (u != p) {
            multiset<int> d = dfs2(u, v);
            if (size(cur) < size(d)) swap(cur, d);
            for (auto j : d)
                cur.insert(j);
        }

    for (auto i : add[v])
        cur.insert(i);
    for (auto i : rem[v])
        cur.erase(cur.find(i));

    ans[{min(v, p), max(v, p)}] = (size(cur) ? *begin(cur) : -1);

    return cur;
}

int main() {
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({min(a, b), max(a, b)});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (h[a] < h[b]) swap(a, b);

        int num = h[a] - h[b];

        int lca = a;

        for (int j = 0; j < MS; j++)
            if (num & (1 << j))
                lca = jmp[j][lca];

        if (lca != b) {
            int cb = b;
            for (int j = MS - 1; j >= 0; j--)
                if (jmp[j][cb] != jmp[j][lca]) {
                    cb = jmp[j][cb];
                    lca = jmp[j][lca];
                }
            lca = jmp[0][lca];

            rem[lca].push_back(c);
            add[b].push_back(c);
        }

        rem[lca].push_back(c);
        add[a].push_back(c);
    }

    dfs2(1, 0);

    for (int i = 0; i < n - 1; i++) {
        cout << ans[edges[i]] << '\n';
    }
}
