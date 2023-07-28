#include "bits/stdc++.h"
using namespace std;

struct Edge {
	int u, v;
	long long w;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<Edge> e(m);
	for (int i = 0; i < m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;

	vector<long long> d(n + 1, 1e18);
	vector<int> p(n + 1, -1);
	int c = -1;
	for (int i = 0; i < n; i++) {
		c = -1;
		for (auto j : e) {
			if (d[j.v] > d[j.u] + j.w) {
				d[j.v] = d[j.u] + j.w;
				p[j.v] = j.u;
				c = j.v;
			}
		}
	}

	if (c == -1) {
		cout << "NO\n";
	} else {
		for (int i = 0; i < n; i++) c = p[c];
		vector<int> ans;
		for (int v = c;; v = p[v]) {
			ans.push_back(v);
			if (v == c && size(ans) > 1) break;
		}
		reverse(begin(ans), end(ans));
		cout << "YES\n";
		for (int i = 0; i < size(ans); i++)
			cout << ans[i] << " \n"[i + 1 == size(ans)];
	}
}
