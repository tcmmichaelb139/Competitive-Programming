#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("empty.in", "r", stdin);
	freopen("empty.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> num(n, 0);
	for (int i = 0; i < k; i++) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		for (long long j = 1; j <= y; j++) {
			num[(a * j + b) % n] += x;
		}
	}
	for (int runs = 0; runs < 2; runs++) {
		for (int i = 0; i < n; i++) {
			if (num[i] <= 1) continue;
			num[(i + 1) % n] += num[i] - 1;
			num[i] = 1;
		}
	}

	for (int i = 0; i < n; i++)
		if (num[i] == 0) {
			cout << i << '\n';
			return 0;
		}
}
