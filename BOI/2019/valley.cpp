#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100'001, MS = 18;
const long long INF = 1e18;

int n, s, q, e;
vector<pair<int, long long>> adj[MAXN];
vector<pair<int, int>> edge;
bool shop[MAXN];
int h[MAXN];
long long dist[MAXN];
long long mn[MS][MAXN];
int jmp[MS][MAXN];

void dfs(int u, int p, int ht) {
	if (shop[u]) mn[0][u] = 0;
	for (auto v : adj[u]) {
		if (v.first == p) continue;
		dist[v.first] = dist[u] + v.second;
		h[v.first] = ht + 1;
		jmp[0][v.first] = u;
		dfs(v.first, u, ht + 1);
		mn[0][u] = min(mn[0][u], mn[0][v.first] + v.second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> q >> e;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		edge.push_back({a, b});
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	for (int i = 0; i < s; i++) {
		int a;
		cin >> a;
		shop[a] = true;
	}
	for (int i = 1; i <= n; i++) mn[0][i] = INF;
	mn[0][e] = 0;
	dfs(e, 0, 0);
	for (int i = 1; i <= n; i++) {
		if (mn[0][i] != INF)
			mn[0][i] -= dist[i];
	}

	for (int i = 1; i < MS; i++) {
		for (int j = 1; j <= n; j++) {
			jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][jmp[i - 1][j]]);
		}
	}

	auto sameSubtree = [&](int a, int b) {
		int diff = h[a] - h[b];
		for (int i = MS - 1; i >= 0; i--)
			if (diff & (1 << i))
				a = jmp[i][a];
		return a == b;
	};

	while (q--) {
		int a, v;
		cin >> a >> v;
		a--;
		int u = edge[a].first;
		if (h[u] < h[edge[a].second]) u = edge[a].second;
		if (h[u] <= h[v] && sameSubtree(v, u)) {
			long long initDist = dist[v];
			long long ans = INF;
			int diff = h[v] - h[u];
			for (int i = MS - 1; i >= 0; i--) {
				if (diff & (1 << i)) {
					ans = min(ans, mn[i][v]);
					v = jmp[i][v];
				}
			}
			ans = min(ans, mn[0][u]);
			if (ans == INF) {
				cout << "oo\n";
			} else {
				cout << initDist + ans << '\n';
			}
		} else {
			cout << "escaped\n";
		}
	}
}
