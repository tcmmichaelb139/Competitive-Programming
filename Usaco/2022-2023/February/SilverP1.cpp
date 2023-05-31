#include "bits/stdc++.h"
using namespace std;

void solve() {
	long long n, tc, tm;
	cin >> n >> tc >> tm;

	vector<long long> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	auto check = [&](long long m) {
		long long d = tc + tm - m;
		long long mn = max(1ll, tc - m), mx = min(d - 1, tc);
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				mn = max(mn, (b[i] * d - c[i] + (b[i] - a[i] - 1)) / (b[i] - a[i]));
			} else if (b[i] < a[i]) {
				mx = min(mx, (c[i] - b[i] * d) / (a[i] - b[i]));
			} else {
				if (a[i] * d > c[i]) return false;
			}
		}
		return mn <= mx;
	};

	long long l = 0, r = tc + tm - 2;
	while (l < r) {
		long long mid = l + (r - l) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
