#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

void solve() {
	long long a, b; cin >> a >> b;
	if (b == 0) {
		cout << 1 << '\n';
		return;
	}
	map<long long, long long> m;
	m[0] = 1;
	m[1] = a;
	long long ind = 1;
	while (ind*2 <= b) {
		a = (a*a)%mod;
		ind *= 2;
		m[ind] = a%mod;
	}
	b -= ind;
	for (long long i = 1<<30; i >= 1; i >>= 1) {
		while (b-i >= 0) {
			b -= i;
			a = (a*m[i])%mod;
		}
	}
	cout << a << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) solve();
}
