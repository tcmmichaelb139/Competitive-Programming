#include <bits/stdc++.h>
using namespace std;

int n;
int ar[251][251];
bool vis1[251][251], vis2[251][251];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
map<pair<pair<int, int>, pair<int, int>>, bool> m;
int ans1 = 0, ans2 = 0;
set<pair<int, int>> s;

int ff2(int i, int j, int val1, int val2) {
	if (i < 0 || j < 0 || i >= n || j >= n) return 0;
	if (vis2[i][j]) return 0;
	if (ar[i][j] != val1 && ar[i][j] != val2) return 0;
	m[{{i, j}, {val1, val2}}] = true;
	vis2[i][j] = true;
	int sol = 1;
	for (int a = 0; a < 4; a++) 
		sol += ff2(i+dx[a], j+dy[a], val1, val2);
	return sol;
}

int ff1(int i, int j, int val1) {
	if (i < 0 || j < 0 || i >= n || j >= n) return 0;
	if (vis1[i][j]) return 0;
	if (ar[i][j] != val1) {
		memset(vis2, false, sizeof(vis2));
		if (!m[{{i, j}, {val1, ar[i][j]}}])
			ans2 = max(ans2, ff2(i, j, val1, ar[i][j]));
		return 0;
	}
	vis1[i][j] = true;
	int sol = 1;
	for (int a = 0; a < 4; a++) 
		sol += ff1(i+dx[a], j+dy[a], val1);
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> ar[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis1[i][j]) continue;
			ans1 = max(ans1, ff1(i, j, ar[i][j]));
		}
	}
	cout << ans1 << '\n';
	cout << ans2 << '\n';
}

