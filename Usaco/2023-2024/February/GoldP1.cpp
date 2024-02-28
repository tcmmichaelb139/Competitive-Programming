#pragma GCC optimize("O3,unroll-loops")  // we love cheese
#include "bits/stdc++.h"
using namespace std;

struct Node {
	int v;
	long long dist;

	bool operator<(const Node &o) const {
		return dist < o.dist;
	}
};

const int MAXN = 50'001;

int n, m, c, r, k;
vector<pair<int, long long>> adj[MAXN];
bool vis[MAXN];
pair<int, long long> top10[MAXN][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c >> r >> k;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 10; j++)
			top10[i][j] = {-1, -1};
	}

	auto combine = [&](int a, int b, long long len) {
		map<int, long long> pos;
		for (int i = 0; i < 10; i++) {
			if (top10[a][i].first == -1) break;
			pos[top10[a][i].first] = top10[a][i].second;
		}
		for (int i = 0; i < 10; i++) {
			if (top10[b][i].second == -1) break;
			if (top10[b][i].second < len) break;  // might be < and not <=
			pos[top10[b][i].first] = max(pos[top10[b][i].first], top10[b][i].second - len);
		}

		vector<pair<int, long long>> opt;
		for (auto i : pos) {
			opt.push_back(i);
		}
		sort(begin(opt), end(opt), [](pair<int, long long> a, pair<int, long long> b) {
			return a.second > b.second;
		});

		for (int i = 0; i < min(10, (int)size(opt)); i++)
			top10[a][i] = opt[i];
	};

	for (int run = 0; run < 6; run++) {
		memset(vis, false, sizeof vis);
		priority_queue<Node> q;
		for (int i = 1; i <= c; i++) {
			q.push({i, 0});
			top10[i][0] = {i, r};
		}

		while (!q.empty()) {
			Node v = q.top();
			q.pop();

			if (vis[v.v]) continue;
			vis[v.v] = true;

			for (auto u : adj[v.v]) {
				/* cout << u.first << ' ' << v.v << '\n'; */
				combine(u.first, v.v, u.second);
				q.push({u.first, u.second + v.dist});
			}
		}
	}

	vector<int> ans;
	for (int i = c + 1; i <= n; i++) {
		int num = 0;
		for (int j = 0; j < 10; j++)
			if (top10[i][j].second != -1) num++;
		if (num >= k) ans.push_back(i);
	}
	cout << size(ans) << '\n';
	for (int i = 0; i < size(ans); i++)
		cout << ans[i] << '\n';
}
