#include "bits/stdc++.h"
using namespace std;

const int MAXX = 1'000'000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m[a]++;
	}

	vector<long long> lsum(MAXX + 1, 0), rsum(MAXX + 1, 0);
	int num = 0;
	for (int i = 0; i <= MAXX; i++) {
		num += m[i];
		if (i) lsum[i] = lsum[i - 1];
		lsum[i] += num;
	}

	num = 0;
	for (int i = MAXX; i >= 0; i--) {
		num += m[i];
		if (i != MAXX) rsum[i] = rsum[i + 1];
		rsum[i] += num;
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;

		auto test = [&](int p) {
			long long res = 0;
			if (p > 0) res += lsum[p - 1] * a;
			if (p < MAXX) res += rsum[p + 1] * b;
			return res;
		};

		int l = 0, r = MAXX;
		while (r - l > 3) {
			int m1 = l + (r - l) / 3;
			int m2 = r - (r - l) / 3;
			if (test(m1) < test(m2))
				r = m2;
			else
				l = m1;
		}

		long long ans = test(l);
		for (int i = l + 1; i <= r; i++) {
			ans = min(ans, test(i));
		}
		cout << ans << '\n';
	}
}
