/*
ID: tcmmich1
LANG: C++
TASK: runround
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	int n;
	cin >> n;
	n++;
	bool done = false;
	while (!done) {
		done = true;
		string s = to_string(n);
		vector<int> v(s.length());
		vector<bool> t(s.length(), false);
		bool again = false;
		for (int i = 0; i < s.length(); i++) {
			if (t[s[i]-'0']) {
				again = true;
				break;
			}
			v[i] = s[i]-'0';
			t[s[i]-'0'] = true;
		}
		if (again || t[0]) {
			n++;
			done = false;
			continue;
		}
		t = vector<bool>(s.length(), false);
		int curr = 0;
		for (int i = 0; i < v.size(); i++) {
			curr += v[curr];
			curr %= v.size();
			if (t[curr]) {
				done = false;
				break;
			}
			t[curr] = true;
		}
		n++;
	}
	cout << n-1 << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

