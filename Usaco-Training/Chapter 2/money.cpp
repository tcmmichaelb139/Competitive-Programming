/*
ID: tcmmich1
TASK: money
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int v, n; cin >> v >> n;
	vector<long long> coins(v);
	for (int i = 0; i < v; i++) {
		cin >> coins[i];
	}
	long long dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int j = 0; j < v; j++) {
		for (int i = 0; i < n; i++) {
			if (coins[j]+i > n) continue;
			dp[coins[j]+i] += dp[i];
		}
	}
	cout << dp[n] << '\n';
}
