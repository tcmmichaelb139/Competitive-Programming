#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s.length() < 3) {
			cout << -1 << '\n';
			continue;
		}
		int ans = (int)s.length() - 3;
		int best = 3;
		for (int i = 0; i < s.length() - 2; i++) {
			string k = s.substr(i, 3);
			if (k == "MOO")
				best = 0;
			else if (k == "OOO" || k == "MOM")
				best = min(best, 1);
			else if (k == "OOM")
				best = min(best, 2);
		}
		cout << (best == 3 ? -1 : ans + best) << '\n';
	}
}
