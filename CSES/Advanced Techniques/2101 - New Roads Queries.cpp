#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    void init(int n) { v = vector<int>(n, -1); }
    int sameSet(int a, int b) { return get(a) == get(b); }
    int get(int a) { return v[a] < 0 ? a : v[a] = get(v[a]); }
    int size(int a) { return -v[get(a)]; }
    int unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a] > v[b]) swap(a, b);
        v[a] += v[b];
        v[b] = a;
        return true;
    }
};

const int MAXN = 200001, MS = 20;

int n, m, q;
vector<pair<pair<int, int>, int>> edgesBefore, edgesAfter;
vector<pair<int, int>> adj[MAXN];
int group[MAXN];
int h[MAXN];
int jmp[MS][MAXN];
int mx[MS][MAXN];

void dfs(int v, int p, int val, int hei) {
    jmp[0][v] = p;
    mx[0][v] = val;
    h[v] = hei;
    for (auto u : adj[v]) {
        if (u.first == p) continue;
        group[u.first] = group[v];
        dfs(u.first, v, u.second, hei + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edgesBefore.push_back({{a, b}, i + 1});
    }

    DSU dsu;
    dsu.init(n + 1);

    for (auto u : edgesBefore)
        if (dsu.unite(u.first.first, u.first.second))
            edgesAfter.push_back(u);
    for (auto u : edgesAfter) {
        adj[u.first.first].push_back({u.first.second, u.second});
        adj[u.first.second].push_back({u.first.first, u.second});
    }

    for (int i = 1; i <= n; i++) {
        if (group[i]) continue;

        group[i] = i;
        dfs(i, 0, -1, 0);
    }

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++) {
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][jmp[i - 1][j]]);
        }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (group[a] != group[b]) {
            cout << -1 << '\n';
        } else if (a == b) {
            cout << 0 << '\n';
        } else {
            if (h[a] < h[b]) swap(a, b);
            int num = h[a] - h[b];
            int ans1 = 0, ans2 = 0;
            for (int j = 0; j < MS; j++)
                if (num & (1 << j)) {
                    ans1 = max(ans1, mx[j][a]);
                    a = jmp[j][a];
                }

            if (a != b) {
                for (int j = MS - 1; j >= 0; j--) {
                    if (jmp[j][a] != jmp[j][b]) {
                        ans1 = max(ans1, mx[j][a]);
                        ans2 = max(ans2, mx[j][b]);
                        a = jmp[j][a];
                        b = jmp[j][b];
                    }
                }
                ans1 = max(ans1, mx[0][a]);
                ans2 = max(ans2, mx[0][b]);
            }

            cout << max(ans1, ans2) << '\n';
        }
    }
}
