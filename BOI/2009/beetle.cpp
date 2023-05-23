#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(begin(v), end(v));

	int dp[n + 1][n + 1][n + 1][2];
	memset(dp, 0, sizeof dp);

	int p = (int)(lower_bound(begin(v), end(v), 0) - begin(v));

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int l = 0; l <= n; l++) {
			for (int r = l; r <= n; r++) {
				dp[i][l][r][0] = dp[i][l][r][1] = 1e9;
				if (l != 0) dp[i][l][r][0] = min(dp[i][l][r][0], dp[i - 1][l - 1][r][0] + i * (v[l] - v[l - 1]));
				if (r != n) dp[i][l][r][0] = min(dp[i][l][r][0], dp[i - 1][l][r + 1][1] + i * (v[r + 1] - v[l]));
				if (l != 0) dp[i][l][r][1] = min(dp[i][l][r][1], dp[i - 1][l - 1][r][0] + i * (v[r] - v[l - 1]));
				if (r != n) dp[i][l][r][1] = min(dp[i][l][r][1], dp[i - 1][l][r + 1][1] + i * (v[r + 1] - v[r]));
			}
		}
		ans = max(ans, i * m - dp[i][p][p][0]);
	}
	cout << ans << '\n';
}
