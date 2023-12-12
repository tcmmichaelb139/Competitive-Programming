#include "bits/stdc++.h"
using namespace std;

long long MOD = 1'000'000'007;
long long add(long long a, long long b) { return ((a + b) % MOD + MOD) % MOD; }

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];

	long long dp[n][m];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;

	vector<long long> total(m, 0);
	total[0] = 1;

	map<int, long long> pref[m];
	pref[0][v[0][0]] = 1;

	for (int i = 1; i < n; i++) {
		long long curTotal = total[0];
		map<int, long long> cur = pref[0];

		for (int j = 1; j < m; j++) {
			dp[i][j] = add(dp[i][j], add(curTotal, -cur[v[i][j]]));

			curTotal = add(curTotal, total[j]);
			total[j] = add(total[j], dp[i][j]);

			for (auto x : pref[j])
				cur[x.first] = add(cur[x.first], x.second);
			pref[j][v[i][j]] = add(pref[j][v[i][j]], dp[i][j]);
		}
	}

	cout << dp[n - 1][m - 1] << '\n';
}
