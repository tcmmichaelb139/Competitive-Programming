#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1001;

vector<pair<int, int>> route[MAXN];

int main() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int s, e, n;
	cin >> s >> e >> n;
	vector<vector<int>> path(n);
	vector<long long> cost(n);
	for (int i = 0; i < n; i++) {
		long long c;
		int m;
		cin >> c >> m;
		cost[i] = c;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			path[i].push_back(a);
			route[a].push_back({i, j});
		}
	}

	vector<bool> vis(MAXN, false);
	vector<long long> dist(MAXN, -1), flights(MAXN, -1);
	dist[s] = 0;
	flights[s] = 0;

	for (int i = 0; i < MAXN; i++) {
		int v = -1;
		for (int j = 1; j < MAXN; j++)
			if ((v == -1 || dist[j] < dist[v]) && dist[j] != -1 && !vis[j])
				v = j;

		if (v == -1) break;
		vis[v] = true;

		for (auto flight : route[v]) {
			int fn = flight.first;
			for (int a = flight.second + 1; a < (int)size(path[fn]); a++) {
				if (dist[path[fn][a]] == -1 || dist[path[fn][a]] > dist[v] + cost[fn]) {
					dist[path[fn][a]] = dist[v] + cost[fn];
					flights[path[fn][a]] = flights[v] + a - flight.second;
				} else if (dist[path[fn][a]] == dist[v] + cost[fn]) {
					flights[path[fn][a]] = min(flights[path[fn][a]], flights[v] + a - flight.second);
				}
			}
		}
	}

	cout << dist[e] << ' ' << flights[e] << '\n';
}
