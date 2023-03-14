#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
vector<int> v[MAXN];
vector<int> adj[MAXN];
int deg[MAXN];
vector<int> ans;

bool test(int k) {
    ans.clear();

    for (int i = 0; i <= n; i++) adj[i].clear();
    memset(deg, 0, sizeof deg);

    for (int i = 0; i < k; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            adj[v[i][j - 1]].push_back(v[i][j]);
            deg[v[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(begin(adj[i]), end(adj[i]));
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i]) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();

        ans.push_back(u);

        for (auto w : adj[u])
            if (--deg[w] == 0)
                q.push(w);
    }

    return ans.size() == n;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;

        if (test(mid))
            l = mid;
        else
            r = mid - 1;
    }

    test(l);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i + 1 == n];
}
