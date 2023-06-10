#include "bits/stdc++.h"
using namespace std;

using Matrix = array<array<long long, 2>, 2>;

const long long MOD = 1'000'000'007;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

Matrix mul(Matrix a, Matrix b) {
	Matrix res = {{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][j] = add(res[i][j], mult(a[i][k], b[k][j]));
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	Matrix res = {{{1, 0}, {0, 1}}};
	Matrix a = {{{1, 1}, {1, 0}}};
	while (n) {
		if (n & 1)
			res = mul(res, a);
		a = mul(a, a);
		n >>= 1;
	}
	cout << res[0][1] << '\n';
}
