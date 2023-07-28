#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100'001;

int n;
vector<int> adj[MAXN];
long long len[MAXN];
pair<long long, long long> dp1[MAXN], dp2[MAXN];

void dfs1(int v, int p) {
	if (!size(adj[v])) dp1[v] = {1, len[v]};
	for (auto u : adj[v]) {
		if (u == p) continue;
		dfs1(u, v);
		dp1[v].first += dp1[u].first;
		dp1[v].second += dp1[u].first * (len[v] + 1) + dp1[u].second;
	}
}

void dfs2(int v, int p) {
	long long total = 0;
	for (auto u : adj[v]) {
		if (u == p) continue;
		total += dp1[u].second;
	}
	for (auto u : adj[v]) {
		if (u == p) continue;

		dp2[u].first = dp2[v].first + dp1[v].first - dp1[u].first;
		dp2[u].second = total - dp1[u].second + (dp2[v].first + dp1[v].first - dp1[u].first) * 3 + dp2[v].second;

		dfs2(u, v);
	}
}

int main() {
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		int k;
		cin >> s >> k;
		len[i] = s.length();
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}

	dfs1(1, 0);

	dfs2(1, 0);

	long long ans = 1e18;
	for (int i = 1; i <= n; i++) {
		if (!size(adj[i])) continue;
		ans = min(ans, dp1[i].second + dp2[i].second - dp1[i].first * (len[i] + 1));
	}
	cout << ans << '\n';
}
