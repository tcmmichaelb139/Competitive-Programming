/*
ID: tcmmich1
TASK: stamps
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;
int ar[50];
int dp[2000001]; //dp[value] = min num of coins;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	
	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	for (int i = 0; i <= 2000000; i++) 
		dp[i] = 1e9;
	dp[0] = 0;
	int ind = 0;
	while (dp[ind] != 1e9 && dp[ind] <= k) {
		for (int i = 0; i < n; i++)
			if (ind+ar[i] < 2000000)
				dp[ind+ar[i]] = min(dp[ind+ar[i]], dp[ind]+1);
		ind++;
	}
	cout << ind-1 << '\n';
}
