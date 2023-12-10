#include "bits/stdc++.h"
using namespace std;

struct DSU {
	vector<int> v;
	void init(int n) { v = vector<int>(n, -1); }
	int sameSet(int a, int b) { return get(a) == get(b); }
	int get(int a) { return v[a] < 0 ? a : v[a] = get(v[a]); }
	int size(int a) { return -v[get(a)]; }
	int unite(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		if (v[a] > v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
		return true;
	}
};

pair<int, int> mnf(int a, int b) {
	return {min(a, b), max(a, b)};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	multiset<pair<int, int>> curDeg;
	vector<int> deg(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	for (int i = 1; i <= n; i++) {
		curDeg.insert({deg[i], i});
	}

	vector<int> order;
	vector<bool> active(n + 1, true);
	while (!curDeg.empty()) {
		pair<int, int> v = *begin(curDeg);
		curDeg.erase(begin(curDeg));
		active[v.second] = false;

		order.push_back(v.second);
		for (auto u : adj[v.second]) {
			if (!active[u]) continue;
			curDeg.erase({deg[u], u});
			curDeg.insert({--deg[u], u});
		}
	}

	DSU dsu;
	dsu.init(n + 1);
	reverse(begin(order), end(order));

	active = vector<bool>(n + 1, false);
	deg = vector<int>(n + 1, 0);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int v = order[i];
		active[v] = true;
		for (auto u : adj[v]) {
			if (active[u]) {
				dsu.unite(u, v);
				deg[u]++;
				deg[v]++;
			}
		}
		ans = max(ans, dsu.size(v) * deg[v]);
	}

	cout << ans << '\n';
}
