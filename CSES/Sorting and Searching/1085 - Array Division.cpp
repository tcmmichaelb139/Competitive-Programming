#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(v[i], mx);
	}
	v.push_back(0);
	long long l = 0, r = 1e18;
	while (l < r) {
		long long mid = l+(r-l+1)/2;
		long long curr = 0;
		int done = 0;
		for (int i = 0; i < n; i++) {
			curr += v[i];
			if (curr > mid) {
				curr = v[i];
				done++;
			}
		}
		if (curr >= v[n-1]) 
			done++;
		if (done <= k && mx <= mid)
			r = mid-1;
		else 
			l = mid;
	}
	cout << l+1 << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

