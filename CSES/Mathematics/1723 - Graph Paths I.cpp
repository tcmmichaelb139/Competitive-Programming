#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1'000'000'007;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

const int MAXN = 101;

struct Matrix {
	array<array<long long, MAXN>, MAXN> a;

	Matrix() {
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++) a[i][j] = 0;
	}

	Matrix operator*(const Matrix &b) {
		Matrix res;
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				for (int k = 0; k < MAXN; k++) {
					res.a[i][j] = add(res.a[i][j], mult(a[i][k], b.a[k][j]));
				}
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	Matrix sol;
	Matrix base;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		base.a[a][b] += 1;
	}

	for (int i = 0; i < n; i++)
		sol.a[i][i] = 1;

	for (; k; k >>= 1, base = base * base)
		if (k & 1) sol = sol * base;

	cout << sol.a[0][n - 1] << '\n';
}
