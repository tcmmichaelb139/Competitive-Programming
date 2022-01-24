#include <bits/stdc++.h>
using namespace std;

int n, m; 
char ar[51][51];

int main() {
	freopen("crosswords.in", "r", stdin);
	freopen("crosswords.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) 
			ar[i][j] = s[j];
	}
	set<pair<int, int>> ans;
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m; j++) 
			if (i-1 < 0 || ar[i-1][j] == '#') 
				if (ar[i][j] == '.' && ar[i+1][j] == '.' && ar[i+2][j] == '.')
					ans.insert({i+1, j+1});
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-2; j++) 
			if (j-1 < 0 || ar[i][j-1] == '#') 
				if (ar[i][j] == '.' && ar[i][j+1] == '.' && ar[i][j+2] == '.')
					ans.insert({i+1, j+1});
	}
	cout << ans.size() << '\n';
	for (auto i: ans)
		cout << i.first << ' ' << i.second << '\n';
}
