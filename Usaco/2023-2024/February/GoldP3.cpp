#include "bits/stdc++.h"
using namespace std;

struct Node {
	int i, j;
	long long time;

	bool operator<(const Node &o) const {
		if (time == o.time) return i < o.i;
		return time < o.time;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<long long> p(n), s(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> s[i];

	auto getTime = [&](int a, int b) {
		long long time = ((p[b] - p[a] + s[a] + s[b] - 1) / (s[a] + s[b])) * 2 - 1;
		if (a & 1) {
			if (time & 1) time++;
		} else {
			if (time % 2 == 0) time++;
		}
		return time;
	};

	vector<Node> endHere(n, {-1, -1, -1}), startHere(n, {-1, -1, -1});
	set<Node> cur;
	for (int i = 0; i < n - 1; i++) {
		long long time = getTime(i, i + 1);
		cur.insert({i, i + 1, time});
		endHere[i + 1] = {i, i + 1, time};
		startHere[i] = {i, i + 1, time};
	}
	vector<long long> ans(n, -1);
	while (size(cur)) {
		Node c = *begin(cur);
		cur.erase(begin(cur));
		if (ans[c.i] != -1 || ans[c.j] != -1) continue;
		int nl = endHere[c.i].i;
		int nr = startHere[c.j].j;
		if (nl != -1)
			cur.erase(endHere[c.i]);
		if (nr != -1)
			cur.erase(startHere[c.j]);

		ans[c.i] = ans[c.j] = c.time;

		if (nl == -1 || nr == -1) {
			if (nl != -1)
				endHere[nl] = {-1, -1, -1};
			if (nr != -1)
				startHere[nr] = {-1, -1, -1};
			continue;
		}

		startHere[nl] = {nl, nr, getTime(nl, nr)};
		endHere[nr] = {nl, nr, getTime(nl, nr)};
		cur.insert({nl, nr, getTime(nl, nr)});
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}
