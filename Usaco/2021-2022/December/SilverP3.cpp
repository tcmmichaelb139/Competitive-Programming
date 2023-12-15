#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(n);
	vector<long long> s(m + 1), e(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		s[v[i].first]++;
		e[v[i].second]++;
	}
	vector<long long> pref(m * 2 + 2, 0);
	vector<long long> start, end;
	for (int i = 0; i <= m; i++) {
		if (s[i] == 0) continue;
		for (int j = 0; j <= m; j++) {
			if (s[j] == 0) continue;
			pref[i + j] += s[i] * s[j];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (e[i] == 0) continue;
		for (int j = 0; j <= m; j++) {
			if (e[j] == 0) continue;
			pref[i + j + 1] -= e[i] * e[j];
		}
	}
	for (int i = 1; i <= 2 * m; i++) {
		pref[i] += pref[i - 1];
	}
	for (int i = 0; i <= 2 * m; i++)
		cout << pref[i] << '\n';
}
