#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		l[i]--;
	}

	int lH = -1, lG = -1;
	int eH = -1, eG = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'H') {
			if (lH == -1)
				lH = i;
			eH = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			if (lG == -1)
				lG = i;
			eG = i;
		}
	}

	int ans = 0;
	if (l[lH] >= eH) {
		for (int i = 0; i < lH; i++) {
			if (s[i] == 'G' && l[i] >= lH) {
				ans++;
			}
		}
	}
	if (l[lG] >= eG) {
		for (int i = 0; i < lG; i++) {
			if (s[i] == 'H' && l[i] >= lG) {
				ans++;
			}
		}
	}

	if (lH > lG) swap(lH, lG);
	if (l[lH] + 1 == lG && lH == 0) {
		bool ok = true;
		for (int i = 0; i < lG; i++)
			if (s[i] != s[lH]) ok = false;
		for (int i = lG; i < n; i++)
			if (s[i] != s[lG]) ok = false;
		if (ok) ans++;
	}
	cout << ans << '\n';
}
