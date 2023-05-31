#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1505;

int n, m, k;
int pref[MAXN][MAXN];
int topLeft[MAXN][MAXN], topRight[MAXN][MAXN];
int bottomLeft[MAXN][MAXN], bottomRight[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];
int b[MAXN][MAXN], t[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			pref[i][j] = a + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			int val = pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k];

			topLeft[i][j] = val;
			topRight[i][j - k + 1] = val;
			bottomLeft[i - k + 1][j] = val;
			bottomRight[i - k + 1][j - k + 1] = val;

			l[i][j] = val;
			r[i][j - k + 1] = val;
			b[i - k + 1][j] = val;
			t[i][j] = val;
		}
	}

	for (int i = k; i <= n; i++)
		for (int j = k; j <= m; j++)
			topLeft[i][j] = max(topLeft[i][j], max(topLeft[i - 1][j], topLeft[i][j - 1]));
	for (int i = k; i <= n; i++)
		for (int j = m - k + 1; j >= 1; j--)
			topRight[i][j] = max(topRight[i][j], max(topRight[i - 1][j], topRight[i][j + 1]));
	for (int i = n - k + 1; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			bottomLeft[i][j] = max(bottomLeft[i][j], max(bottomLeft[i + 1][j], bottomLeft[i][j - 1]));
	for (int i = n - k + 1; i >= 1; i--)
		for (int j = m - k + 1; j >= 1; j--)
			bottomRight[i][j] = max(bottomRight[i][j], max(bottomRight[i + 1][j], bottomRight[i][j + 1]));

	for (int i = k; i <= n; i++)
		for (int j = k; j <= m; j++)
			l[i][j] = max(l[i][j], l[i][j - 1]);
	for (int i = k; i <= n; i++)
		for (int j = m - k + 1; j >= 1; j--)
			r[i][j] = max(r[i][j], r[i][j + 1]);
	for (int j = 1; j <= m; j++)
		for (int i = n - k + 1; i >= 1; i--)
			b[i][j] = max(b[i][j], b[i + 1][j]);
	for (int j = k; j <= m; j++)
		for (int i = k; i <= n; i++)
			t[i][j] = max(t[i][j], t[i - 1][j]);

	auto ansLeft = [&](int i, int j) {
		int r = topRight[i - k][j - k + 1];
		r = max(r, topRight[n][j + 1]);
		r = max(r, bottomRight[i + 1][j - k + 1]);
		return topLeft[n][j - k] + r;
	};

	auto ansRight = [&](int i, int j) {
		int l = topLeft[i - k][j];
		l = max(l, topLeft[n][j - k]);
		l = max(l, bottomLeft[i + 1][j]);
		return l + topRight[n][j + 1];
	};

	auto ansBottom = [&](int i, int j) {
		int t = topLeft[i][j - k];
		t = max(t, topLeft[i - k][m]);
		t = max(t, topRight[i][j + 1]);
		return bottomLeft[i + 1][m] + t;
	};

	auto ansTop = [&](int i, int j) {
		int b = bottomLeft[i - k + 1][j - k];
		b = max(b, bottomLeft[i + 1][m]);
		b = max(b, bottomRight[i - k + 1][j + 1]);
		return b + topLeft[i - k][m];
	};

	int ans = 0;
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			int val = pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k];

			ans = max(ans, ansLeft(i, j) + val);
			ans = max(ans, ansRight(i, j) + val);
			ans = max(ans, ansBottom(i, j) + val);
			ans = max(ans, ansTop(i, j) + val);
		}
	}

	cout << ans << '\n';
}
