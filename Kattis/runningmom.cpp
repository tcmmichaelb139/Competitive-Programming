#include "bits/stdc++.h"
using namespace std;

const int MAXN = 5e3 + 1;
enum { UNVISITED = 0,
       VISITED = -1,
       EXPLORED = -2 };

int n;
vector<int> adj[MAXN];
map<string, int> m;

int vis[MAXN];
bool safe;

void dfs(int v) {
    vis[v] = EXPLORED;
    for (auto u : adj[v]) {
        if (vis[u] == EXPLORED) {
            safe = true;
            return;
        }
        dfs(u);
    }
    vis[v] = VISITED;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num = 1;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if (m[s] == 0)
            m[s] = num++;
        if (m[t] == 0)
            m[t] = num++;

        int ms = m[s], mt = m[t];
        adj[ms].push_back(mt);
    }
    string q;
    while (cin >> q) {
        memset(vis, UNVISITED, sizeof vis);
        safe = false;
        dfs(m[q]);
        cout << q << ' ' << (safe ? "safe" : "trapped") << '\n';
    }
}
