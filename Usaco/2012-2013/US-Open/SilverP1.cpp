#include<bits/stdc++.h>
using namespace std;

int n, m; 
char ar[501][501];
bool vis[501][501][2];
pair<int, int> bov, beef;
int dy[] = {1, -1};

bool check(int x, int y, bool dir) {
	if (dir) {
		if (x <= 0) return false;
		if (ar[x-1][y] == '#') return false;
	} else {
		if (x >= n-1) return false;
		if (ar[x+1][y] == '#') return false;
	}
	return true;
}

int main() {
	freopen("gravity.in", "r", stdin);
	freopen("gravity.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'C')
				bov = {i, j};
			if (s[j] == 'D') 
				beef = {i, j};
			ar[i][j] = s[j];
		}
	}
	// dist, grav, x, y
	priority_queue<pair<pair<int, int>, pair<int, int>>,
		vector<pair<pair<int, int>, pair<int, int>>>,
		greater<pair<pair<int, int>, pair<int, int>>>> q;
	vis[bov.first][bov.second][0] = true;
	q.push({{0, 0}, bov});
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> k = q.top();
		q.pop();
		if (k.second == beef) {
			cout << k.first.first << '\n';
			return 0;
		}
		if (k.first.second) {
			pair<int, int> x = {k.second.first-1, k.second.second};
			if (x.first >= 0 && ar[x.first][x.second] != '#' && !vis[x.first][x.second][1]) {
				vis[x.first][x.second][1] = true;
				q.push({k.first, x});
			} else if (x.first >= 0 && ar[x.first][x.second] == '#') {
				for (int i = 0; i < 2; i++) {
					x = {k.second.first, k.second.second+dy[i]};
					if (x.second >= 0 && x.second < m && !vis[x.first][x.second][1] && ar[x.first][x.second] != '#') {
						vis[x.first][x.second][1] = true;
						q.push({k.first, x});
					}
				}
				x = {k.second.first+1, k.second.second};
				if (x.first < n && !vis[x.first][x.second][0] && ar[x.first][x.second] != '#') {
					vis[x.first][x.second][0] = true;
					q.push({{k.first.first+1, false}, x});
				}
			}
		} else {
			pair<int, int> x = {k.second.first+1, k.second.second};
			if (x.first < n && ar[x.first][x.second] != '#' && !vis[x.first][x.second][0]) {
				vis[x.first][x.second][0] = true;
				q.push({k.first, x});
			} else if (x.first < n && ar[x.first][x.second] == '#') {
				for (int i = 0; i < 2; i++) {
					x = {k.second.first, k.second.second+dy[i]};
					if (x.second >= 0 && x.second < m && !vis[x.first][x.second][0] && ar[x.first][x.second] != '#') {
						vis[x.first][x.second][0] = true;
						q.push({k.first, x});
					}
				}
				x = {k.second.first-1, k.second.second};
				if (x.first >= 0 && !vis[x.first][x.second][1] && ar[x.first][x.second] != '#') {
					vis[x.first][x.second][1] = true;
					q.push({{k.first.first+1, true}, x});
				}
			}
		}
	}
	cout << -1 << '\n';
}
