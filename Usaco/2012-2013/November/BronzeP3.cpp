#include <bits/stdc++.h>
using namespace std;

int n; 
char ar[6][6];
bool vis[6][6];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int ans = 0;

void dfs(int i, int j, int l, int r, bool x) {
	if (l == r) {
		ans = max(ans, l+r); 
		return;
	}
	if (x && 2*l <= ans) return;
	vis[i][j] = true;
	for (int a = 0; a < 4; a++) {
		pair<int, int> k = {dx[a]+i, dy[a]+j};
		if (k.first < 0 || k.second < 0 || k.first >= n || k.second >= n) continue;
		if (!vis[k.first][k.second]) {
			if (ar[k.first][k.second] == ')')
				dfs(k.first, k.second, l, r+1, true);
			else if (!x)
				dfs(k.first, k.second, l+1, r, false);
		}
	}
	vis[i][j] = false;
}

int main() {
	freopen("hshoe.in", "r", stdin);
	freopen("hshoe.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) 
			ar[i][j] = s[j];
	}
	if (ar[0][0] == '(')
		dfs(0, 0, 1, 0, false);
	cout << ans << '\n';
}
