#include "bits/stdc++.h"
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
	map<char, char> m;
	map<char, set<char>> mRev;
	for (int i = 0; i < s.length(); i++) {
		if (m.find(s[i]) != end(m) && m[s[i]] != t[i]) {
			cout << -1 << '\n';
			return;
		}
		m[s[i]] = t[i];
		mRev[t[i]].insert(s[i]);
	}

	int ans = 0;

	map<char, bool> done;

	for (auto i : m) {
		if (i.first == i.second) continue;
		if (done[i.first]) continue;

		char cur = i.second;
		int sz = 1;

		map<char, bool> vis;
		vis[i.first] = true;
		vector<char> loop;
		bool good = false;

		while (m.find(cur) != m.end()) {
			if (size(mRev[cur]) > 1) good = true;
			loop.push_back(cur);
			if (vis[cur]) break;
			vis[cur] = true;
			cur = m[cur];
			sz++;
		}

		if (cur == i.first) {
			if (good)
				ans += sz;
			else {
				if (size(mRev) == 52) {
					cout << -1 << '\n';
					return;
				}
				ans += sz + 1;
			}
			for (auto j : loop) done[j] = true;
		} else {
			ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
