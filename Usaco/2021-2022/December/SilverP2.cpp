#include "bits/stdc++.h"
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> comp(n + 1, -1);
	vector<vector<long long>> comps;
	for (long long i = 1; i <= n; i++) {
		if (comp[i] != -1) continue;
		queue<long long> q;
		q.push(i);
		comp[i] = (int)size(comps);
		comps.push_back({i});
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (auto u : adj[v])
				if (comp[u] == -1) {
					comp[u] = comp[v];
					comps[comp[i]].push_back(u);
					q.push(u);
				}
		}
	}

	int bc = comp[1], ec = comp[n];

	for (vector<long long> &c : comps)
		sort(begin(c), end(c));

	vector<long long> bl(size(comps), 1e18), br(size(comps), 1e18);
	for (long long i = 1; i <= n; i++) {
		auto it = lower_bound(begin(comps[bc]), end(comps[bc]), i);
		if (it != end(comps[bc]))
			bl[comp[i]] = min(bl[comp[i]], (i - *it) * (i - *it));
		if (it != begin(comps[bc])) {
			it--;
			bl[comp[i]] = min(bl[comp[i]], (i - *it) * (i - *it));
		}
	}
	for (long long i = 1; i <= n; i++) {
		auto it = lower_bound(begin(comps[ec]), end(comps[ec]), i);
		if (it != end(comps[ec]))
			br[comp[i]] = min(br[comp[i]], (i - *it) * (i - *it));
		if (it != begin(comps[ec])) {
			it--;
			br[comp[i]] = min(br[comp[i]], (i - *it) * (i - *it));
		}
	}

	long long ans = 1e18;
	for (int i = 0; i < (int)size(comps); i++) {
		ans = min(ans, bl[i] + br[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
