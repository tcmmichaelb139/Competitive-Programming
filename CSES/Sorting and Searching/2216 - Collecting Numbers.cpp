#include <bits/stdc++.h>
using namespace std;

int n; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (v[i].second > v[i+1].second) 
			ans++;
	}
	cout << ans+1 << '\n';
}
