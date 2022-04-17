#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> adj[100001];
bool vis[100001];
int ans = 0;

void dfs(int k) {
    int infec = 0;
    for (auto i: adj[k]) 
        if (vis[i]) 
            infec++;
    long long tmp = 1;
    while (tmp <= adj[k].size()-infec)
        tmp *= 2, ans++;
    for (auto i: adj[k]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[1] = true;
    dfs(1);
    cout << ans << '\n';
}
