#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	while (cin >> n >> m >> q) {
		if (n == 0) break;
		int d[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) d[i][j] = (i == j ? 0 : INF);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			d[u][v] = min(d[u][v], w);
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (d[i][k] < INF && d[k][j] < INF)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (d[i][k] < INF && d[k][k] < 0 && d[k][j] < INF)
						d[i][j] = -INF;

		while (q--) {
			int u, v;
			cin >> u >> v;
			if (d[u][v] == INF) cout << "Impossible\n";
			else if (d[u][v] == -INF) cout << "-Infinity\n";
			else cout << d[u][v] << '\n';
		}
	}
}
