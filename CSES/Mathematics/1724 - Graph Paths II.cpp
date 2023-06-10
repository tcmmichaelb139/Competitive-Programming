#include "bits/stdc++.h"
using namespace std;

int n;

struct Matrix {
	vector<vector<long long>> a = vector<vector<long long>>(n, vector<long long>(n, 2e18));

	Matrix operator*(const Matrix &o) {
		Matrix res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res.a[i][j] = min(res.a[i][j], a[i][k] + o.a[k][j]);
				}
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, k;
	cin >> n >> m >> k;

	Matrix base;
	Matrix sol;

	for (int i = 0; i < n; i++)
		sol.a[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--, b--;

		base.a[a][b] = min(base.a[a][b], c);
	}

	for (; k; k >>= 1, base = base * base)
		if (k & 1) sol = sol * base;

	if (sol.a[0][n - 1] > (long long)1e18)
		cout << -1;
	else
		cout << sol.a[0][n - 1] << '\n';
}
