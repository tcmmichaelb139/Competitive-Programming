#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> f(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i] >> s[i];
	}
	vector<int> ans(n);
	int num = 0;
	vector<int> used(m + 1, -1);
	for (int i = n - 1; i >= 0; i--) {
		int cur = i;
		int pos = f[i];
		while (1) {
			if (used[pos] == -1) {
				used[pos] = cur;
				num++;
				break;
			} else if (used[pos] < cur) {
				break;
			} else {
				int ind = used[pos];
				used[pos] = cur;
				if (pos == s[ind]) break;
				cur = ind;
				pos = s[ind];
			}
		}
		ans[i] = num;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}
