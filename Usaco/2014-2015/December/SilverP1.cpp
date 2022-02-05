#include<bits/stdc++.h>
using namespace std;

long long b, e, p, n, m; 
vector<long long> adj[40001];
long long distfb[40001], distfe[40001], distfj[40001]; //from bessie, from elsie, from barn

void bfs(long long (&distf)[40001], long long who, long long add) {
	bool vis[40001]; memset(vis, false, sizeof(vis));
	queue<long long> q; 
	distf[who] = 0;
	vis[who] = true;
	q.push(who);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (auto i: adj[k]) 
			if (!vis[i]) {
				vis[i] = true;
				distf[i] = distf[k]+add;
				q.push(i);
			}
	}
}

int main() {
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> b >> e >> p >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(distfb, 1, b);
	bfs(distfe, 2, e);
	bfs(distfj, n, p);
	long long ans = 1e9;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, distfb[i]+distfe[i]+distfj[i]);
	}
	cout << ans << '\n';
}
