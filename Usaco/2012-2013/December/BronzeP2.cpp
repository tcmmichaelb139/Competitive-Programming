#include<bits/stdc++.h>
using namespace std;

int n; 

int main() {
	freopen("scramble.in", "r", stdin);
	freopen("scramble.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	vector<string> s(n), l(n);
	vector<string> small(n), large(n);
	for (int i = 0; i < n; i++) {
		small[i] = large[i] = v[i];
		sort(small[i].begin(), small[i].end());
		sort(large[i].rbegin(), large[i].rend());
		s[i] = small[i], l[i] = large[i];
	}
	small.push_back("zzzzzzzzzzzzzzzzzzzzz");
	large.push_back("zzzzzzzzzzzzzzzzzzzzz");
	sort(small.begin(), small.end());
	sort(large.begin(), large.end());
	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; i++) {
		auto tmp1 = lower_bound(small.begin(), small.end(), l[i]);
		auto tmp2 = lower_bound(large.begin(), large.end(), s[i]);
		ans[i].first = tmp1-small.begin();
		ans[i].first += (s[i] < *tmp1 ? -1 : 0);
		ans[i].second = tmp2-large.begin();
		ans[i].second += (l[i] < *tmp2 ? -1 : 0);
	}
	for (int i = 0; i < n; i++) {
		if (ans[i].first > ans[i].second) swap(ans[i].first, ans[i].second);
		cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
	}
}

