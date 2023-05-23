#include "bits/stdc++.h"
using namespace std;

const int MAXN = 301;

int dp[MAXN][MAXN];
int mx[MAXN][MAXN][MAXN];

int main() {
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		for (int j = b; j <= c; j++)
			mx[j][b][c] = max(mx[j][b][c], a);
	}

	for (int i = 1; i <= n; i++) {
		for (int len = 1; len <= n; len++) {
			for (int l = 1, r = len; r <= n; l++, r++) {
				if (l != 0) mx[i][l - 1][r] = max(mx[i][l - 1][r], mx[i][l][r]);
				if (r != n) mx[i][l][r + 1] = max(mx[i][l][r + 1], mx[i][l][r]);
			}
		}
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l++, r++) {
			for (int k = l; k < r; k++) {
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
			for (int k = l; k <= r; k++) {
				int add = mx[k][l][r];
				if (k > l) add += dp[l][k - 1];
				if (k < r) add += dp[k + 1][r];
				dp[l][r] = max(dp[l][r], add);
			}
		}
	}

	cout << dp[1][n] << '\n';
}
