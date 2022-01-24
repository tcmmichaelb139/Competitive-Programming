#include <bits/stdc++.h>
using namespace std;

int n; 

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	pair<int, int> mx = {0, 0};
	for (int i = 1; i < n-1; i++) {
		int k = dist(v[i-1], v[i])+dist(v[i], v[i+1])-dist(v[i-1], v[i+1]);
		if (mx.first < k)
			mx = {k, i};
	}
	v.erase(v.begin()+mx.second);
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += dist(v[i], v[i+1]);
	}
	cout << ans << '\n';
}
