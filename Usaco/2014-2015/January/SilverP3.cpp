#include "bits/stdc++.h"
using namespace std;

struct Path {
	int to;
	int time[2];
};

const int MAXT = 10001;
const int MAXN = 101;

bool dp[2][MAXN][MAXT];

int main() {
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<Path> adj[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		adj[a].push_back({b, {c, d}});
	}

	for (int a = 0; a < 2; a++) {
		dp[a][1][0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < MAXT; j++) {
				if (dp[a][i][j]) {
					for (auto k : adj[i]) {
						dp[a][k.to][j + k.time[a]] = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < MAXT; i++)
		if (dp[0][n][i] && dp[1][n][i]) {
			cout << i << '\n';
			return 0;
		}
	cout << "IMPOSSIBLE\n";
}
