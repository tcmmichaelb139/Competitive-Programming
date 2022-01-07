/*
ID: tcmmich1
TASK: fracdec
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int vis[1000000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	
	int n, d; cin >> n >> d;
	string s = to_string(n/d)+'.'; 
	if (n%d == 0) 
		s += '0';
	else {
		n %= d;
		n *= 10;
		while (true) {
			if (n == 0 || vis[n] != 0) break;
			vis[n] = s.length();
			s += to_string(n/d);
			n %= d;
			n *= 10;
		}
		if (vis[n] != 0)
			s = s.substr(0, vis[n])+'('+s.substr(vis[n])+')';
	}
	for (int i = 0; i < s.size(); i += 76)
		cout << s.substr(i, 76) << '\n';
}
