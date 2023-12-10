#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	auto add = [&](long long a, long long b, long long i) {
		return (h[a] - h[i]) * (b - i) <= (h[b] - h[i]) * (a - i);
	};

	long long ans = 0;

	vector<set<int>> nxt(n);

	auto build = [&](int i) {
		for (int j = i + 1; j < n; j++) {
			if (size(nxt[i]) == 0) {
				nxt[i].insert(j);
				ans++;
			} else if (add(*--end(nxt[i]), j, i)) {
				nxt[i].insert(j);
				ans++;
			}
		}
	};

	for (int i = 0; i < n; i++) {
		build(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--;
		h[x] += y;

		for (int i = 0; i < x; i++) {
			auto it = nxt[i].lower_bound(x);
			if (it != begin(nxt[i]) && *it != x) {
				it--;
				if (add(*it, x, i)) {
					nxt[i].insert(x);
					ans++;
				}
			}
			if (nxt[i].find(x) != end(nxt[i])) {
				it = nxt[i].upper_bound(x);
				while (it != end(nxt[i]) && !add(x, *it, i)) {
					nxt[i].erase(it);
					ans--;
					it = nxt[i].upper_bound(x);
				}
			}
		}

		ans -= size(nxt[x]);
		nxt[x].clear();
		build(x);

		cout << ans << '\n';
	}
}

// nxt[i][j] = next index where we are check mountain i and j is the last one that works.
// sz[i] = number that node can see
//
