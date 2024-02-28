#include "bits/stdc++.h"
using namespace std;

void solve() {
	long long n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(begin(v), end(v));

	auto cost = [&](long long k) {
		multiset<long long> s(begin(v), end(v));
		long long t = 0;
		for (long long i = k; i > 0; i--) {
			t += i;
			auto it = s.lower_bound(t);
			if (it == end(s)) it--;
			s.erase(it);
		}
		return max((size(s) ? *(--end(s)) : 0), (k * (k + 1)) / 2);
	};

	long long l = 0, r = n - 1;
	while (r - l > 10) {
		long long m1 = l + (r - l) / 3;
		long long m2 = r - (r - l) / 3;
		if (cost(m1) < cost(m2))
			r = m2;
		else
			l = m1;
	}
	long long ans = (n * (n + 1)) / 2;
	for (long long i = l; i < r; i++) {
		ans = min(ans, cost(i));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
