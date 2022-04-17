#include<bits/stdc++.h>
using namespace std;

int n, m; 
vector<int> adj[100001];
int parent[100001]; 
bool vis[100001];
vector<int> ans;
bool imp = false;

void dfs(int k) {
    vis[k] = true;
    ans.push_back(k);
    for (auto i: adj[k]) {
        if (--parent[i] == 0) 
            dfs(i);
    }
}

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (parent[i] == 0) 
            q.push(i);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        ans.push_back(k);
        if (vis[k]) continue;
        vis[k] = true;
        for (auto i: adj[k]) {
            if (--parent[i] == 0) 
                q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        parent[b]++;
        adj[a].push_back(b);
    }
    bfs();
    /* for (int i = 1; i <= n; i++) { */
    /*     if (!vis[i] && parent[i] == 0) { */
    /*         dfs(i); */
    /*     } */
    /* } */
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) 
            imp = true;
    if (imp) 
        cout << "IMPOSSIBLE\n";
    else 
        for (int i = 0; i < n; i++) 
            cout << ans[i] << " \n"[i+1 == n];
}
