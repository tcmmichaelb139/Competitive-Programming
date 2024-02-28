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

const int MAXN = 100001, MS = 18;

int n, m, q;
vector<pair<int, int>> adj[MAXN];
int h[MAXN];
int jmp[MS][MAXN];
int mn[MS][MAXN];

void dfs(int u, int p, int hei) {
	h[u] = hei;
	for (auto [v, t] : adj[u]) {
		if (v == p) continue;

		jmp[0][v] = u;
		mn[0][v] = t;

		dfs(v, u, hei + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	vector<pair<int, pair<int, int>>> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}
	sort(rbegin(edges), rend(edges));

	DSU dsu;
	dsu.init(n + 1);

	for (auto [t, uv] : edges) {
		if (dsu.unite(uv.first, uv.second)) {
			adj[uv.first].push_back({uv.second, t});
			adj[uv.second].push_back({uv.first, t});
		}
	}

	for (int i = 0; i < MS; i++)
		for (int j = 0; j < MAXN; j++)
			mn[i][j] = 1e9;

	dfs(1, 0, 0);

	for (int i = 1; i < MS; i++) {
		for (int j = 1; j <= n; j++) {
			jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][jmp[i - 1][j]]);
		}
	}

	auto findAnswer = [&](int a, int b) {
		if (h[a] < h[b]) swap(a, b);
		int ans = 1e9;
		int diff = h[a] - h[b];
		for (int i = MS - 1; i >= 0; i--)
			if (diff & (1 << i)) {
				ans = min(ans, mn[i][a]);
				a = jmp[i][a];
			}

		for (int i = MS - 1; i >= 0; i--) {
			if (jmp[i][a] != jmp[i][b]) {
				ans = min(ans, mn[i][a]);
				ans = min(ans, mn[i][b]);
				a = jmp[i][a];
				b = jmp[i][b];
			}
		}

		if (a == b) return ans;

		ans = min(ans, mn[0][a]);
		ans = min(ans, mn[0][b]);
		return ans;
	};

	int x = 0;
	while (q--) {
		int a, b, t;
		cin >> a >> b >> t;
		if (findAnswer(a ^ x, b ^ x) >= (t ^ x)) {
			x++;
			cout << "Jebb\n";
		} else {
			cout << "Neibb\n";
		}
	}
}
