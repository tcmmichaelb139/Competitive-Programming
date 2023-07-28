#include "bits/stdc++.h"
using namespace std;

struct Edge {
	int u, v;
	int w;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q, s;
	while (cin >> n >> m >> q >> s) {
		if (n == 0) break;
		vector<Edge> e(m);
		for (int i = 0; i < m; i++)
			cin >> e[i].u >> e[i].v >> e[i].w;

		set<int> left;
		vector<int> d(n + 1, 1e9);
		d[s] = 0;
		vector<int> p(n + 1, -1);
		for (int i = 0; i < n; i++) {
			for (auto j : e) {
				if (d[j.u] == (int)1e9) continue;
				if (d[j.v] > d[j.u] + j.w) {
					d[j.v] = d[j.u] + j.w;
					p[j.v] = j.u;
					if (i == n - 1) left.insert(j.v);
				}
			}
		}

		vector<bool> ninf(n + 1, false);
		for (auto i : left) {
			for (int j = 0; j < n; j++) i = p[i];
			ninf[i] = true;
		}

		for (int i = 0; i < n; i++)
			for (auto j : e)
				ninf[j.v] = ninf[j.v] || ninf[j.u];

		while (q--) {
			int u;
			cin >> u;
			if (ninf[u]) {
				cout << "-Infinity\n";
			} else if (d[u] == (int)1e9) {
				cout << "Impossible\n";
			} else {
				cout << d[u] << '\n';
			}
		}
	}
}
