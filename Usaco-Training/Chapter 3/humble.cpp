/*
ID: tcmmich1
TASK: humble
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int k, n;
long long S[100];
long long ans[100001];
long long pre[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> S[i];
	}
	ans[0] = 1;
	for (int i = 1; i <= n; i++) {
		long long mn = 1e18;
		for (int j = 0; j < k; j++) {
			while (S[j]*ans[pre[j]] <= ans[i-1])
				pre[j]++;
			mn = min(mn, S[j]*ans[pre[j]]);
		}
		ans[i] = mn;
	}
	cout << ans[n] << '\n';
}
