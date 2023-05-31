#include "bits/stdc++.h"
using namespace std;

const int dx[] = {0, 1}, dy[] = {1, 0};
const int MAXN = 1505;

int n;
int dir[MAXN][MAXN], cost[MAXN][MAXN];
int num[MAXN][MAXN];

int dfs(pair<int, int> v, int add) {
	num[v.first][v.second] = 1;
	int sum = add;
	for (int a = 0; a < 2; a++) {
		pair<int, int> u = {v.first - dx[a], v.second - dy[a]};
		if (u.first < 0 || u.second < 0) continue;
		if (a != dir[u.first][u.second]) continue;
		sum += dfs(u, add);
		num[v.first][v.second] += num[u.first][u.second];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int c;
		cin >> s >> c;
		for (int j = 0; j < n; j++)
			dir[i][j] = s[j] == 'D';
		cost[i][n] = c;
	}
	for (int i = 0; i < n; i++)
		cin >> cost[n][i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dir[n - 1][i])
			ans += dfs({n - 1, i}, cost[n][i]);
		if (!dir[i][n - 1])
			ans += dfs({i, n - 1}, cost[i][n]);
	}

	auto findCostAndUpd = [&](pair<int, int> i, int sub) {
		while (i.first != n && i.second != n) {
			i = {i.first + dx[dir[i.first][i.second]],
			     i.second + dy[dir[i.first][i.second]]};
			num[i.first][i.second] -= sub;
		}
		return cost[i.first][i.second];
	};

	cout << ans << '\n';

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		ans -= num[a][b] * findCostAndUpd({a, b}, num[a][b]);
		dir[a][b] ^= 1;
		ans += num[a][b] * findCostAndUpd({a, b}, -num[a][b]);

		cout << ans << '\n';
	}
}
