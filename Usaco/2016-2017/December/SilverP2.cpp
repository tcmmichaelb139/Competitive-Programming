#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int n; cin >> n;
	vector<pair<string, string>> v(n);
	map<string, int> m; //state -> index
	vector<multiset<string>> s(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (m[v[i].second] == 0)
			m[v[i].second] = i+1;
		s[m[v[i].second]].insert(v[i].first.substr(0, 2));
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		string k = v[i].first.substr(0, 2);
		if (k == v[i].second) 
			continue;
		if (m[k] == 0) 
			continue;
		ans += s[m[k]].count(v[i].second);
	}
	cout << ans/2 << '\n';
}
