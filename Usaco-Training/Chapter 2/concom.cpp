/*
ID: tcmmich1
TASK: concom
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> adj[100];
int control[100][100];
bool vis[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, p;
		cin >> a >> b >> p;
		a--, b--;
		adj[a].push_back({b, p});
	}
	for (int i = 0; i < 100; i++) {
		memset(vis, false, sizeof(vis));
		queue<int> q;
		q.push(i);
		vis[i] = true;
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (auto a: adj[k]) {
				control[i][a.first] += a.second;
				if (control[i][a.first] > 50 && !vis[a.first]) {
					vis[a.first] = true;
					q.push(a.first);
				}
			}
		}
	}
	/* for (int i = 0; i < 100; i++) { */
	/* 	for (int j = 0; j < 100; j++)  */
	/* 		cout << control[i][j] << '\t'; */
	/* 	cout << '\n'; */
	/* } */
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) 
			if (control[i][j] > 50 && i != j) 
				cout << i+1 << ' ' << j+1 << '\n';
}

