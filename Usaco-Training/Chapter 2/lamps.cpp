/*
ID: tcmmich1
LANG: C++
TASK: lamps
 */
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> on, off;
set<string> ans;
unordered_map<string, bool> vis;

string btos(bitset<101> k) {
	string s = "";
	for (int i = 0; i < n; i++) {
		if (k[i])
			s += '1';
		else 
			s += '0';
	}
	return s;
}

void dfs(bitset<101> k, int times) {
	if (times > c) return;
	if (vis[btos(k)])
		return;
	vis[btos(k)] = true;
	bool ok = true;
	for (int i = 0; i < on.size(); i++) 
		if (k[on[i]] == 0) 
			ok = false;
	for (int i = 0; i < off.size(); i++) 
		if (k[off[i]] == 1)
			ok = false;
	if (ok)
		ans.insert(btos(k));
	bitset<101> k1 = k, k2 = k, k3 = k, k4 = k;
	for (int i = 0; i < n; i+=2) 
		k1.flip(i);
	for (int i = 1; i < n; i+=2)
		k2.flip(i);
	for (int i = 0; i < n; i+=3)
		k3.flip(i);
	k4.flip();
	dfs(k1, times+1);
	dfs(k2, times+1);
	dfs(k3, times+1);
	dfs(k4, times+1);
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n >> c;
	while (true) {
		int e;
		cin >> e;
		if (e == -1) break;
		on.push_back(--e);
	}
	while (true) {
		int e;
		cin >> e;
		if (e == -1) break;
		off.push_back(--e);
	}
	bitset<101> x;
	x.set();
	dfs(x, 0);
	if (!ans.size()) 
		cout << "IMPOSSIBLE" << '\n';
	for (auto i: ans)
		cout << i << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

