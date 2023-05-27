#include "bits/stdc++.h"
using namespace std;

const int MAXN = 51;

int dp[MAXN][MAXN][MAXN][MAXN];  // dp(left index, right index, smallest value, largest value)

int main() {
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int len = 1; len <= n; len++) {
		for (int l = 0, r = len - 1; r < n; l++, r++) {
			if (len == 1) dp[l][r][v[l]][v[l]] = max(dp[l][r][v[l]][v[l]], 1);
			if (len == 2) {
				if (v[l] <= v[r])
					dp[l][r][v[l]][v[r]] = max(dp[l][r][v[r]][v[l]], 2);
				if (v[l] >= v[r])
					dp[l][r][v[r]][v[l]] = max(dp[l][r][v[r]][v[l]], 2);
			}
			for (int lenv = 1; lenv <= MAXN; lenv++) {
				for (int lv = 1, rv = lenv; rv < MAXN; lv++, rv++) {
					if (lv - 1) dp[l][r][lv - 1][rv] = max(dp[l][r][lv - 1][rv], dp[l][r][lv][rv]);
					if (rv + 1 < MAXN) dp[l][r][lv][rv + 1] = max(dp[l][r][lv][rv + 1], dp[l][r][lv][rv]);
					if (l) dp[l - 1][r][lv][rv] = max(dp[l - 1][r][lv][rv], dp[l][r][lv][rv]);
					if (r + 1 < n) dp[l][r + 1][lv][rv] = max(dp[l][r + 1][lv][rv], dp[l][r][lv][rv]);
					if (l && v[l - 1] <= lv) dp[l - 1][r][v[l - 1]][rv] = max(dp[l - 1][r][v[l - 1]][rv], dp[l][r][lv][rv] + 1);
					if (r + 1 < n && rv <= v[r + 1]) dp[l][r + 1][lv][v[r + 1]] = max(dp[l][r + 1][lv][v[r + 1]], dp[l][r][lv][rv] + 1);

					if (l && r + 1 < n) {
						if (v[r + 1] <= lv && rv <= v[l - 1])
							dp[l - 1][r + 1][v[r + 1]][v[l - 1]] = max(dp[l - 1][r + 1][v[r + 1]][v[l - 1]], dp[l][r][lv][rv] + 2);
						if (v[r + 1] <= lv)
							dp[l - 1][r + 1][v[r + 1]][rv] = max(dp[l - 1][r + 1][v[r + 1]][rv], dp[l][r][lv][rv] + 1);
						if (rv <= v[l - 1])
							dp[l - 1][r + 1][lv][v[l - 1]] = max(dp[l - 1][r + 1][lv][v[l - 1]], dp[l][r][lv][rv] + 1);
					}
				}
			}
		}
	}

	cout << dp[0][n - 1][1][MAXN - 1] << '\n';
}
