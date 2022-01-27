#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	vector<int> dp;
	for (int i = 0; i < n; i++) {
		int k = lower_bound(dp.begin(), dp.end(), v[i])-dp.begin();
		if (k == dp.size())
			dp.push_back(v[i]);
		else 
			dp[k] = v[i];
	}
	cout << dp.size() << '\n';
}

