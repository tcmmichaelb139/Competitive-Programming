#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0 && i*i == n) ans++;
		else if (n%i == 0) ans += 2;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) solve();
}
