#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> bale(n);
	for (int i = 0; i < n; i++) {
		cin >> bale[i].first >> bale[i].second;
	}
	sort(begin(bale), end(bale), [](pair<int, int> a, pair<int, int> b) {
		if (a.second < b.second) return true;
		return false;
	});

	vector<pair<int, int>> ranges;
	set<pair<int, int>> reach;
	set<int> start;
	for (int i = 0; i < n; i++) {
		while (size(reach) && begin(reach)->first < bale[i].second) {
			start.erase(bale[begin(reach)->second].second);
			reach.erase(begin(reach));
		}
		auto it = start.lower_bound(bale[i].second - bale[i].first);
		if (it != end(start))
			ranges.push_back({*it, bale[i].second});
		reach.insert({bale[i].second + bale[i].first, i});
		start.insert(bale[i].second);
	}

	reverse(begin(ranges), end(ranges));
	int ans = 0;
	pair<int, int> cur = ranges[0];
	for (int i = 1; i < (int)size(ranges); i++) {
		int l = ranges[i].first, r = ranges[i].second;
		if (r >= cur.first) {
			cur.first = min(cur.first, l);
		} else {
			ans += cur.second - cur.first;
			cur = {l, r};
		}
	}
	ans += cur.second - cur.first;
	cout << ans << '\n';
}
