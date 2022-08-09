#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e3 + 1;

int n;
map<string, int> m;
map<int, string> mr;
vector<int> adj[MAXN];
int vis[MAXN];
int pre[MAXN];

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        pre[u] = v;
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m[s] == 0)
            mr[num] = s, m[s] = num++;
        string t;
        getline(cin, t);
        vector<string> v;
        int pre = 1;
        for (int j = 1; j <= t.length(); j++)
            if (j == t.length() || t[j] == ' ') {
                v.push_back(t.substr(pre, j - 1));
                pre = j + 1;
            }

        for (auto j : v)
            if (m[j] == 0)
                mr[num] = j, m[j] = num++;

        for (auto j : v) {
            int ms = m[s], mj = m[j];
            adj[ms].push_back(mj);
            adj[mj].push_back(ms);
        }
    }

    memset(pre, -1, sizeof pre);

    string a, b;
    cin >> a >> b;

    dfs(m[a]);

    if (pre[m[b]] == -1) {
        cout << "no route found\n";
    } else {
        vector<string> ans;
        for (int i = m[b]; i != -1; i = pre[i])
            ans.push_back(mr[i]);

        reverse(begin(ans), end(ans));
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
