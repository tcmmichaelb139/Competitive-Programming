/*
ID: tcmmich1
TASK: inflate
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int m, n;
int dp[10001]; // amount of time -> maximum points
pair<int, int> ar[10000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i].first >> ar[i].second;
	for (int i = 0; i <= m; i++) 
		dp[i] = -1e9;
	dp[0] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) 
			if (i+ar[j].second <= m) 
				dp[i+ar[j].second] = max(dp[i+ar[j].second], dp[i]+ar[j].first);
	}
	int ans = 0;
	for (int i = 0; i <= m; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}
