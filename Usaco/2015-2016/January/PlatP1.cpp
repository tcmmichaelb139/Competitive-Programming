#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> site(n);
	vector<vector<int>> nd(n, vector<int>(1, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		site[i] = s;
		for (int j = 0; j < m; j++) {
			nd[i].push_back(nd[i].back() + (s[j] == '.'));
		}
	}

	int ans = 0;

	vector<vector<int>> fence(m, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int a = 0; a < m; a++) {
			for (int b = a; b < m; b++) {
				if (nd[i][b + 1] - nd[i][a] == b - a + 1) {
					if (fence[a][b] != -1)
						ans = max(ans, (b - a + 1) * (i - fence[a][b] + 1));
					else
						fence[a][b] = i;
				}
				if (site[i][a] == 'X' || site[i][b] == 'X') {
					fence[a][b] = -1;
				}
			}
		}
	}

	cout << ans << '\n';
}
