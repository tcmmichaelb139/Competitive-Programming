#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100'000;
const int K = 320;

int n, m, q;
vector<int> adj[MAXN];
vector<int> revAdj[MAXN];
vector<pair<int, int>> kvals[MAXN];
bool done[MAXN];
int dp[MAXN];
bool busy[MAXN];

void dfs(int v) {
	if (!size(kvals[v]))
		kvals[v].push_back({0, v});
	for (auto u : revAdj[v]) {
		if (!size(kvals[u]))
			dfs(u);
		vector<pair<int, int>> nxt;
		auto itv = begin(kvals[v]);
		auto itu = begin(kvals[u]);
		while (itv != end(kvals[v]) && itu != end(kvals[u]) && size(nxt) < K) {
			if (done[itv->second]) {
				itv++;
				continue;
			}
			if (done[itu->second]) {
				itu++;
				continue;
			}
			if (itv->first > itu->first + 1) {
				done[itv->second] = true;
				nxt.push_back(*(itv++));
			} else {
				done[itu->second] = true;
				nxt.push_back({itu->first + 1, itu->second});
				itu++;
			}
		}
		while (itv != end(kvals[v]) && size(nxt) < K) {
			if (!done[itv->second]) {
				done[itv->second] = true;
				nxt.push_back(*itv);
			}
			itv++;
		}
		while (itu != end(kvals[u]) && size(nxt) < K) {
			if (!done[itu->second]) {
				done[itu->second] = true;
				nxt.push_back({itu->first + 1, itu->second});
			}
			itu++;
		}
		for (auto i : nxt) done[i.second] = false;
		swap(kvals[v], nxt);
	}
}

void solve(int v) {
	done[v] = true;
	if (!busy[v])
		dp[v] = 0;
	for (auto u : revAdj[v]) {
		if (!done[u])
			solve(u);

		if (dp[u] == -1) continue;
		dp[v] = max(dp[v], dp[u] + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		revAdj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (size(adj[i])) continue;

		dfs(i);
	}

	while (q--) {
		int t, y;
		cin >> t >> y;
		t--;
		vector<int> b(y);
		for (int i = 0; i < y; i++) {
			cin >> b[i];
			b[i]--;
			busy[b[i]] = true;
		}

		int ans = -1;
		if (y < K) {
			for (auto i : kvals[t])
				if (!busy[i.second]) {
					ans = i.first;
					break;
				}
		} else {
			for (int i = 0; i < n; i++) dp[i] = -1;
			memset(done, false, sizeof done);
			solve(t);
			ans = dp[t];
		}
		cout << ans << '\n';
		for (auto i : b) busy[i] = false;
	}
}
