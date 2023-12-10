#include "bits/stdc++.h"
using namespace std;

struct DSU {
	vector<int> v;
	vector<vector<int>> in;
	void init(int n) {
		v = vector<int>(n, -1);
		in = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) in[i].push_back(i);
	}
	int sameSet(int a, int b) { return get(a) == get(b); }
	int get(int a) { return v[a] < 0 ? a : v[a] = get(v[a]); }
	int size(int a) { return -v[get(a)]; }
	int unite(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		if (v[a] > v[b]) swap(a, b);
		for (auto u : in[b]) in[a].push_back(u);
		in[b].clear();
		v[a] += v[b];
		v[b] = a;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> e;
	vector<pair<char, int>> que;
	vector<bool> rel(n, true);
	vector<bool> rem(q, false);
	for (int i = 0; i < q; i++) {
		char c;
		cin >> c;
		if (c != 'A') {
			int a;
			cin >> a;
			a--;
			que.push_back({c, a});
			if (c == 'D')
				rel[a] = false;
			else
				rem[a] = true;
		} else {
			int a, b;
			cin >> a >> b;
			a--, b--;
			e.push_back({a, b});
			que.push_back({c, a});
		}
	}

	DSU dsu;
	dsu.init(n);

	vector<int> ans(n, 0);

	auto conn = [&](int u, int v, int i) {
		if (dsu.sameSet(u, v)) return;
		if (rel[u] && !rel[v]) {
			for (auto j : dsu.in[dsu.get(v)]) {
				rel[j] = true;
				ans[j] = q - i - 1;
			}
		} else if (!rel[u] && rel[v]) {
			for (auto j : dsu.in[dsu.get(u)]) {
				rel[j] = true;
				ans[j] = q - i - 1;
			}
		}
		dsu.unite(u, v);
	};

	for (int i = 0; i < n; i++) {
		if (rel[i]) ans[i] = q;
	}
	for (int i = 0; i < size(e); i++) {
		if (!rem[i]) {
			int u, v;
			tie(u, v) = e[i];
			conn(u, v, -1);
		}
	}

	reverse(begin(que), end(que));

	for (int i = 0; i < size(que); i++) {
		if (que[i].first == 'R') {
			int u, v;
			tie(u, v) = e[que[i].second];
			conn(u, v, i);
		} else if (que[i].first == 'D') {
			int u = que[i].second;
			if (rel[u]) continue;
			for (auto j : dsu.in[dsu.get(u)]) rel[j] = true, ans[j] = q - i - 1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}
