#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	double n;
	while (cin >> n) {
		if (n == 0) break;
		double k = 1;
		while (k*k*k <= n)
			k++;
		k--;
		double l = ((n-(k*k*k))/(3*k*k));
		k += l;
		cout << fixed << setprecision(4) << k << '\n';
	}
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

