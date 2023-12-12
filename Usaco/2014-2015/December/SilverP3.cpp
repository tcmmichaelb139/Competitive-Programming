#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	vector<pair<int, int>> cow(n);
	for (int i = 0; i < n; i++) {
		cin >> cow[i].first >> cow[i].second;
	}

	stack<pair<int, int>> s;
	s.push(cow[n - 1]);

	for (int i = n - 2; i >= 0; i--) {
		if (cow[i].second < s.top().second) {
			s.push(cow[i]);
		} else if ((s.top().first - cow[i].first + cow[i].second - s.top().second - 1) / (cow[i].second - s.top().second) > t) {
			s.push(cow[i]);
		}
	}

	cout << size(s) << '\n';
}
