#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	long long n;
	while (cin >> n) {
		if (n == 0) break;
		long long a, b; cin >> a >> b;
		map<int, int> m;
		long long i = 0;
		long long left = n;
		while (true) {
			m[i]++;
			if (m[i] == 2) 
				left--;
			if (m[i] == 3) 
				break;
			long long i2 = (i*i)%n;
			i2 *= a; i2 %= n;
			i2 += b; i2 %= n;
			i = i2;
		}
		cout << left << '\n';
	}
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

