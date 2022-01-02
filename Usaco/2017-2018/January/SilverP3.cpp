#include <bits/stdc++.h>
using namespace std;

int n, q;
int k;
vector<pair<int, int>> adj[5000];
bool vis[5000];

int dfs(int x, int mn) {
	int ans = (mn >= k ? 1 : 0);
	for (auto i: adj[x]) {
		if (vis[i.first]) continue;
		vis[i.first] = true;
		ans += dfs(i.first, min(i.second, mn));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	cin >> n >> q;
	for (int i = 0; i < n-1; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		a--, b--;
		adj[a].push_back({b, r});
		adj[b].push_back({a, r});
	}
	for (int i = 0; i < q; i++) {
		memset(vis, false, sizeof(vis));
		int v;
		cin >> k >> v;
		v--;
		vis[v] = true;
		cout << dfs(v, 1e9+1)-1 << '\n';
	}
}
