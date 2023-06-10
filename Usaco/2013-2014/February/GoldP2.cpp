#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("dec.in", "r", stdin);
	freopen("dec.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b;

	vector<vector<pair<int, int>>> bon(n);
	for (int i = 0; i < b; i++) {
		int k, p, a;
		cin >> k >> p >> a;

		bon[k - 1].push_back({p, a});
	}
	vector<vector<int>> cow(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cow[i][j];

	int dp[1 << n];
	for (int i = 0; i < 1 << n; i++) dp[i] = -1e9;

	dp[0] = 0;

	for (int e = 0; e <= n; e++) {
		for (int i = 0; i < 1 << n; i++) {
			if (__builtin_popcount(i) != e) continue;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) continue;

				dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + cow[j][e]);
			}
		}
		for (int i = 0; i < 1 << n; i++)
			if (__builtin_popcount(i) == e + 1)
				for (int j = 0; j < size(bon[e]); j++)
					if (dp[i] >= bon[e][j].first)
						dp[i] += bon[e][j].second;
	}

	cout << dp[(1 << n) - 1] << '\n';
}
