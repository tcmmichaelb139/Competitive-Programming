#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	int c, n; cin >> c >> n;
	multiset<long long> t;
	vector<pair<long long, long long>> v(n);
	for (int i = 0; i < c; i++) {
		int a; cin >> a;
		t.insert(a);
	}
	for (int i = 0; i < n; i++) 
		cin >> v[i].first >> v[i].second;
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> q;
	for (int i = 0; i < n; i++) 
		q.push({v[i].second, v[i].first});
	int ans = 0;
	while (!q.empty()) {
		pair<int, int> k = q.top(); q.pop();
		auto it = t.lower_bound(k.second);
		if (it != t.end() && *it <= k.first) {
			t.erase(it);
			ans++;
		}
	}
	cout << ans << '\n';
}
