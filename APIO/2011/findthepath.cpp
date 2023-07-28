#include "bits/stdc++.h"
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct Hive {
	int x1, y1;
	int x2, y2;
};

struct Edge {
	int x, y;
	int dist;
};

struct Node {
	int x, y;
	int dist;

	/* void print() { */
	/* 	cout << "x: " << x << " y: " << y << '\t' << "dist: " << dist << '\t' << "dx: " << dx << " dy: " << dy << '\n'; */
	/* } */

	bool operator<(const Node &o) const {
		return dist > o.dist;
	}
};

void solve() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int n;
	cin >> n;
	vector<Hive> h(n);
	vector<int> cc[2];
	for (int i = 0; i < n; i++) {
		cin >> h[i].x1 >> h[i].y1 >> h[i].x2 >> h[i].y2;
		if (h[i].x1 > h[i].x2) swap(h[i].x1, h[i].x2);
		if (h[i].y1 > h[i].y2) swap(h[i].y1, h[i].y2);
		cc[0].push_back(h[i].x1);
		cc[0].push_back(h[i].x2);
		cc[1].push_back(h[i].y1);
		cc[1].push_back(h[i].y2);
	}

	cc[0].push_back(tx);
	cc[0].push_back(sx);
	cc[1].push_back(sy);
	cc[1].push_back(ty);

	for (int i = 0; i < 2; i++) {
		sort(begin(cc[i]), end(cc[i]));
		cc[i].erase(unique(begin(cc[i]), end(cc[i])), end(cc[i]));
	}

	auto xcc = [&](int x) { return (int)(lower_bound(begin(cc[0]), end(cc[0]), x) - begin(cc[0])); };
	auto ycc = [&](int y) { return (int)(lower_bound(begin(cc[1]), end(cc[1]), y) - begin(cc[1])); };

	sx = xcc(sx);
	tx = xcc(tx);
	sy = ycc(sy);
	ty = ycc(ty);
	for (int i = 0; i < n; i++) {
		h[i].x1 = xcc(h[i].x1);
		h[i].x2 = xcc(h[i].x2);
	}
	for (int i = 0; i < n; i++) {
		h[i].y1 = ycc(h[i].y1);
		h[i].y2 = ycc(h[i].y2);
	}

	vector<Edge> adj[size(cc[0])][size(cc[1])];

	int hive[size(cc[0])][size(cc[1])];
	memset(hive, 0, sizeof hive);

	for (int i = 0; i < n; i++) {
		for (int x = h[i].x1; x <= h[i].x2; x++) {
			hive[x][h[i].y1] = hive[x][h[i].y2] = i + 1;
			if (x < h[i].x2) {
				adj[x][h[i].y1].push_back({x + 1, h[i].y1, cc[0][x + 1] - cc[0][x]});
				adj[x][h[i].y2].push_back({x + 1, h[i].y2, cc[0][x + 1] - cc[0][x]});
			}
			if (x > h[i].x1) {
				adj[x][h[i].y1].push_back({x - 1, h[i].y1, cc[0][x] - cc[0][x - 1]});
				adj[x][h[i].y2].push_back({x - 1, h[i].y2, cc[0][x] - cc[0][x - 1]});
			}
		}
		for (int y = h[i].y1; y <= h[i].y2; y++) {
			hive[h[i].x1][y] = hive[h[i].x2][y] = i + 1;
			if (y < h[i].y2) {
				adj[h[i].x1][y].push_back({h[i].x1, y + 1, cc[1][y + 1] - cc[1][y]});
				adj[h[i].x2][y].push_back({h[i].x2, y + 1, cc[1][y + 1] - cc[1][y]});
			}
			if (y > h[i].y1) {
				adj[h[i].x1][y].push_back({h[i].x1, y - 1, cc[1][y] - cc[1][y - 1]});
				adj[h[i].x2][y].push_back({h[i].x2, y - 1, cc[1][y] - cc[1][y - 1]});
			}
		}
	}

	hive[sx][sy] = -1;
	hive[tx][ty] = -2;

	for (int x = 0; x < (int)size(cc[0]); x++) {
		int py = -1;
		for (int y = 0; y < (int)size(cc[1]); y++) {
			if (hive[x][y] != 0) {
				if (py != -1 && hive[x][py] != hive[x][y]) {
					adj[x][py].push_back({x, y, cc[1][y] - cc[1][py]});
					adj[x][y].push_back({x, py, cc[1][y] - cc[1][py]});
				}
				py = y;
			}
		}
	}
	for (int y = 0; y < (int)size(cc[1]); y++) {
		int px = -1;
		for (int x = 0; x < (int)size(cc[0]); x++) {
			if (hive[x][y] != 0) {
				if (px != -1 && hive[px][y] != hive[x][y]) {
					adj[px][y].push_back({x, y, cc[0][x] - cc[0][px]});
					adj[x][y].push_back({px, y, cc[0][x] - cc[0][px]});
				}
				px = x;
			}
		}
	}

	bool vis[size(cc[0])][size(cc[1])];
	memset(vis, false, sizeof vis);

	priority_queue<Node> q;
	q.push({sx, sy, 0});

	while (!q.empty()) {
		Node v = q.top();
		q.pop();

		if (v.x == tx && v.y == ty) {
			cout << v.dist << '\n';
			return;
		}

		if (vis[v.x][v.y]) continue;
		vis[v.x][v.y] = true;

		for (auto u : adj[v.x][v.y]) {
			if (vis[u.x][u.y]) continue;
			q.push({u.x, u.y, v.dist + u.dist});
		}
	}
	cout << "No Path\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
