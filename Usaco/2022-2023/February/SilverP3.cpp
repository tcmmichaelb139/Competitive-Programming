#include "bits/stdc++.h"
using namespace std;

struct Flight {
	int r, d, s;
};

struct Node {
	int v;
	int time;
	bool first;

	bool operator<(const Node &rhs) const { return time > rhs.time; }
};

const int MAXN = 200'001;

vector<Flight> adj[MAXN];
int dist[MAXN];
int idx[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c, r, d, s;
		cin >> c >> r >> d >> s;
		adj[c].push_back({r, d, s});
	}
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dist[i] = 1e9;
	}

	for (int i = 1; i <= n; i++) {
		sort(begin(adj[i]), end(adj[i]), [](Flight a, Flight b) { return a.r > b.r; });
	}

	priority_queue<Node> q;
	q.push({1, 0, true});
	while (!q.empty()) {
		Node v = q.top();
		q.pop();

		if (dist[v.v] <= v.time) continue;
		dist[v.v] = v.time;

		while (size(adj[v.v]) > idx[v.v] && (adj[v.v][idx[v.v]].r >= v.time + a[v.v] || v.first)) {
			if (dist[adj[v.v][idx[v.v]].d] > adj[v.v][idx[v.v]].s)
				q.push({adj[v.v][idx[v.v]].d, adj[v.v][idx[v.v]].s, false});
			idx[v.v]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << (dist[i] == (int)1e9 ? -1 : dist[i]) << '\n';
}
