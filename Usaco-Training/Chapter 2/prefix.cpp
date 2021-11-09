/*
ID: tcmmich1
LANG: C++
TASK: prefix
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	vector<string> p;
	string s, seq;
	while (cin >> s && s != ".") 
		p.push_back(s);
	while (cin >> s)
		seq += s;
	vector<bool> vis(seq.size()+1, false);
	vis[0] = true;
	for (int i = 0; i < seq.size(); i++) {
		if (!vis[i]) continue;
		for (auto x: p) {
			bool next = true;
			for (int a = 0; a < x.length(); a++) {
				if (seq[i+a] != x[a]) {
					next = false;
					break;
				}
			}
			if (next) {
				vis[x.length()+i] = true;
			}
		}
	}
	for (int x = vis.size(); x >= 0; x--)
		if (vis[x]) {
			cout << x << '\n';
			break;
		}
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

