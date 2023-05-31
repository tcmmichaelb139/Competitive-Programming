#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<long long, int>> v(n);
	vector<long long> val(n + 1, 0);
	vector<long long> sval(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
		sval[i + 1] = val[i + 1] = v[i].first;
	}
	sort(begin(v), end(v));
	sort(begin(sval), end(sval));
	long long sum = 0;
	vector<long long> pref(n + 1, 0);
	vector<int> pos(n, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + v[i].first;
		pos[v[i].second] = i;
		sum += v[i].first * (i + 1);
	}

	int q;
	cin >> q;
	while (q--) {
		int a;
		long long b;
		cin >> a >> b;

		a--;

		if (b <= val[a + 1]) {
			long long ans = sum;
			ans -= (pos[a] + 1) * val[a + 1];
			ans += pref[pos[a]] - pref[upper_bound(begin(sval), end(sval), b) - begin(sval) - 1];
			ans += (upper_bound(begin(sval), end(sval), b) - begin(sval)) * b;
			cout << ans << '\n';
		} else {
			long long ans = sum;
			ans -= (pos[a] + 1) * val[a + 1];
			ans -= pref[lower_bound(begin(sval), end(sval), b) - begin(sval) - 1] - pref[pos[a] + 1];
			ans += (lower_bound(begin(sval), end(sval), b) - begin(sval) - 1) * b;
			cout << ans << '\n';
		}
	}
}
