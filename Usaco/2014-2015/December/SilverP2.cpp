#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> cp(n);
	for (int i = 0; i < n; i++)
		cin >> cp[i].first >> cp[i].second;

	int dp[n][k + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j] = 1e9;

	dp[0][0] = 0;

	auto dist = [&](int i, int j) {
		return abs(cp[i].first - cp[j].first) + abs(cp[i].second - cp[j].second);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int jumps = 0; jumps <= k - j; jumps++) {
				if (i + jumps + 1 >= n) break;
				dp[i + jumps + 1][j + jumps] = min(dp[i + jumps + 1][j + jumps], dp[i][j] + dist(i, i + jumps + 1));
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i <= k; i++)
		ans = min(ans, dp[n - 1][i]);
	cout << ans << '\n';
}
