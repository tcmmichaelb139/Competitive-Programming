#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	set<int> s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> a, b;
		for (int j = 0; j < n; j++) {
			if (v[j].second > v[i].second)
				a.push_back(v[j]);
			else 
				b.push_back(v[j]);
		}
		int bi = 0, ai = 0;
		while (ai < a.size() || bi < b.size()) {
			int x = 1e9;
			if (ai < a.size())
				x = min(x, a[ai].first);
			if (bi < b.size())
				x = min(x, b[bi].first);
			while (bi < b.size() && b[bi].first == x)
				bi++;
			while (ai < a.size() && a[ai].first == x)
				ai++;
			ans = min(ans, max(max(bi, int(b.size())-bi), max(ai, int(a.size())-ai)));
		}
	}
	cout << ans << '\n';
}

