#include "bits/stdc++.h"
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

char ar[10][10];
bool vis[10][10];
int dist[10][10];
int ans = 0;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> ar[i][j];
			if (ar[i][j] == 'L') a = i, b = j;
		}
	}

	queue<pair<int, int>> q;
	q.push({a, b});
	vis[a][b] = true;
	while (!q.empty()) {
		pair<int, int> k = q.front();
		q.pop();

		if (ar[k.first][k.second] == 'B') {
			cout << dist[k.first][k.second] - 1 << '\n';
			break;
		}

		for (int i = 0; i < 4; i++) {
			int na = k.first + dx[i], nb = k.second + dy[i];
			if (na < 0 || nb < 0 || na >= 10 || nb >= 10) continue;
			if (ar[na][nb] == 'R') continue;
			if (vis[na][nb]) continue;
			dist[na][nb] = dist[k.first][k.second] + 1;
			vis[na][nb] = true;
			q.push({na, nb});
		}
	}
}
