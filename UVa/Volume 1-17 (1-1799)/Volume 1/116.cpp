#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		int ar[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ar[i][j];
			}
		}
		priority_queue<pair<int, pair<int, int>>,
			vector<pair<int, pair<int, int>>>,
			greater<pair<int, pair<int,int>>>> q;
		vector<vector<int>> dp(n, vector<int>(m, 1e9));
		vector<vector<int>> prev(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			q.push({ar[i][m-1], {i, m-1}});
			dp[i][m-1] = ar[i][m-1];
			while (!q.empty()) {
				pair<int, pair<int, int>> x = q.top();
				q.pop();
				for (int a = 0; a < 3; a++) {
					pair<int, pair<int, int>> k = x;
					k.second.first += dy[a];
					k.second.second--;
					if (k.second.first >= n)
						k.second.first = 0;
					else if (k.second.first < 0)
						k.second.first = n-1;
					if (k.second.second == -1) 
						break;
					if (dp[k.second.first][k.second.second] == k.first+ar[k.second.first][k.second.second])
						prev[k.second.first][k.second.second] = min(prev[k.second.first][k.second.second], x.second.first);
					if (dp[k.second.first][k.second.second] > k.first+ar[k.second.first][k.second.second]){
						dp[k.second.first][k.second.second] = k.first+ar[k.second.first][k.second.second];
						prev[k.second.first][k.second.second] = x.second.first;
						q.push({k.first+ar[k.second.first][k.second.second], k.second});
					}
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			if (ans > dp[i][0]) {
				ans = dp[i][0];
			}
		}
		vector<int> a;
		for (int i = 0; i < n; i++) {
			if (ans == dp[i][0]) {
				a.push_back(i);
			}
		}
		vector<string> sol;
		for (auto j: a) {
			string s = "";
			for (int i = 0; i < m; i++) {
				s += to_string(j);
				if (i != m-1)
					j = prev[j][i];
			}
			sol.push_back(s);
		}
		sort(sol.begin(), sol.end());
		for (int i = 0; i < sol[0].length(); i++) 
			cout << int(sol[0][i]-'0')+1 << " \n"[i+1 == sol[0].length()];
		cout << ans << '\n';
	}
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

