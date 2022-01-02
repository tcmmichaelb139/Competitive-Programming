#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

	long long l, n, rf, rb; cin >> l >> n >> rf >> rb;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++) {
		long long x, c;
		cin >> x >> c;
		v.push_back({c, x});
	}
	sort(v.rbegin(), v.rend());
	long long ans = v[0].first*v[0].second;
	int prev = v[0].second;
	for (int i = 1; i < n; i++) {
		if (prev > v[i].second) continue;
		ans += (v[i].second-prev)*v[i].first;
		prev = v[i].second;
	}
	cout << ans*(rf-rb) << '\n';
}
