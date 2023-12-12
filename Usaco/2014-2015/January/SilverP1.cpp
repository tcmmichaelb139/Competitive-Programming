#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("stampede.in", "r", stdin);
	freopen("stampede.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set<long long> pos;
	map<long long, vector<int>> add;
	map<long long, vector<int>> rem;
	for (int i = 0; i < n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		long long l = (-x - 1) * r;
		long long u = l + r;
		pos.insert(l);
		pos.insert(u);
		add[l].push_back(y);
		rem[u].push_back(y);
	}

	set<int> cur;
	set<int> ans;
	for (auto i : pos) {
		if (size(cur))
			ans.insert(*begin(cur));
		for (auto j : add[i])
			cur.insert(j);
		for (auto j : rem[i])
			cur.erase(j);
	}

	cout << size(ans) << '\n';
}
