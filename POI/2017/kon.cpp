#include "bits/stdc++.h"
using namespace std;

const int SQ = 320;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> ans(n, 0);

	int dp[n][SQ];
	memset(dp, 0, sizeof dp);

	while (q--) {
		int a, l, d;
		cin >> a >> l >> d;
		a--;
		if (d >= SQ) {
			for (int i = 0; i < l; i++)
				ans[a + i * d]++;
		} else {
			dp[a][d]++;
			if (a + l * d < n)
				dp[a + l * d][d]--;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < SQ; j++)
			if (i - j >= 0)
				dp[i][j] += dp[i - j][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < SQ; j++)
			ans[i] += dp[i][j];
		cout << ans[i] << " \n"[i + 1 == n];
	}
}
