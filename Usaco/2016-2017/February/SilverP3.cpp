#include <bits/stdc++.h>
using namespace std;

int n, k, r; 
int v[101][101];
map<pair<pair<int, int>, pair<int, int>>, bool> w;
bool vis[101][101];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void ff(int i, int j, int val) {
	if (i <= 0 || j <= 0 || i > n || j > n) return;
	if (vis[i][j]) return;
	vis[i][j] = true;
	v[i][j] = val;
	for (int a = 0; a < 4; a++) {
		if (w[{{i, j}, {i+dx[a], j+dy[a]}}])
			continue;
		ff(i+dx[a], j+dy[a], val);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	cin >> n >> k >> r;
	vector<pair<int, int>> c(k);
	memset(v, -1, sizeof(v));
	for (int i = 0; i < r; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		w[{{a, b}, {c, d}}] = true;
		w[{{c, d}, {a, b}}] = true;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i].first >> c[i].second;
	}
	int x = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j]) continue;
			ff(i, j, x);
			x++;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cout << v[i][j] << " \n"[j+1 == n+1];
	int ans = 0;
	for (int i = 0; i < k-1; i++) {
		for (int j = i+1; j < k; j++) {
			if (v[c[i].first][c[i].second] != v[c[j].first][c[j].second])
				ans++;
		}
	}
	cout << ans << '\n';
}
