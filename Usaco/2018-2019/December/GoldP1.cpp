#include<bits/stdc++.h>
using namespace std;

int n, m, k; 
int hay[50002];
vector<pair<int, int>> adj[50002];
vector<pair<int, int>> adjnn[50002];
int d[50002];

void bfs(int x) {
    bool vis[50001]; memset(vis, false, sizeof(vis));
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> q;
    q.push({0, x});
    while (!q.empty()) {
        pair<int, int> k = q.top();
        q.pop();
        if (vis[k.second]) continue;
        vis[k.second] = true;
        d[k.second] = k.first;
        for (auto i: adj[k.second]) {
            q.push({i.first+k.first, i.second});
        }
    }
}


int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    bfs(n);
    int dd[50002];
    for (int i = 0; i <= n; i++) 
        dd[i] = d[i];
    for (int i = 0; i <= n; i++) 
        hay[i] = -1;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        hay[a] = b;
        adj[n+1].push_back({dd[a]-b, a});
    }
    bfs(n+1);
    for (int i = 1; i < n; i++) 
        cout << (d[i] <= dd[i]) << '\n';
}
