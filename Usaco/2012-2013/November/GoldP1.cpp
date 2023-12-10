#include "bits/stdc++.h"
using namespace std;

int MOD = 2012;
int add(int a, int b) { return (a + b) % MOD; }
int mult(int a, int b) { return a * b % MOD; }

int main() {
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = (int)s.length();

	int sum = 0;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			sum++;
		for (int j = 0; j <= i; j++) {
			if (s[i] == '(') {
				dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
				dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
			} else {
				if (j) dp[i + 1][j - 1] = add(dp[i + 1][j - 1], dp[i][j]);
				if (sum - j > 0) dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
			}
		}
		if (s[i] == ')')
			sum--;
	}

	cout << dp[n][0] << '\n';
}
