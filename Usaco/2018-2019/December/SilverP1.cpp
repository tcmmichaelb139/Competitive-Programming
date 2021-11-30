#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int v[100000];

bool possible(int k) {
	int bus = 0;
	int cows = 1;
	int start = v[0];
	for (int i = 1; i < n; i++) {
		cows++;
		if (v[i]-start > k || cows > c) {
			bus++;
			start = v[i];
			cows = 1;
		}
	}
	/* cout << bus << '\n'; */
	if (bus > m-1)
		return false;
	else
		return true;
}

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v+n);
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = l+(r-l)/2;
		if (possible(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

