#include "bits/stdc++.h"
using namespace std;

struct Path {
	int to;
	int dist[2];
};

const int MAXN = 10001;

int n, m;
vector<Path> adj[MAXN];
vector<Path> adj_rev[MAXN];

int main() {
	freopen("gpsduel.in", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		adj[a].push_back({b, {p, q}});
		adj_rev[b].push_back({a, {p, q}});
	}

	vector<vector<int>> dist(2, vector<int>(n + 1, -1));
	for (int a = 0; a < 2; a++) {
		vector<bool> vis(n + 1, false);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, n});
		while (!q.empty()) {
			int d, v;
			tie(d, v) = q.top();
			q.pop();

			if (vis[v]) continue;
			vis[v] = true;

			dist[a][v] = d;

			for (auto u : adj_rev[v]) {
				q.push({d + u.dist[a], u.to});
			}
		}
	}

	vector<bool> vis(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 1});
	while (!q.empty()) {
		int comp, v;
		tie(comp, v) = q.top();
		q.pop();

		if (vis[v]) continue;
		vis[v] = true;

		if (v == n) {
			cout << comp << '\n';
			return 0;
		}

		vector<int> best(2, 1e9);
		for (int i = 0; i < 2; i++) {
			for (auto u : adj[v]) {
				best[i] = min(best[i], dist[i][u.to] + u.dist[i]);
			}
		}

		for (auto u : adj[v]) {
			if (vis[u.to]) continue;

			int add = 0;
			for (int i = 0; i < 2; i++)
				if (best[i] < dist[i][u.to] + u.dist[i]) add++;

			q.push({comp + add, u.to});
		}
	}
}
