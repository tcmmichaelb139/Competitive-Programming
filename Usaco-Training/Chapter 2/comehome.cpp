/*
ID: tcmmich1
TASK: comehome
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> adj[58];
char v[58];
bool vis[58];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c1, c2; int d; cin >> c1 >> c2 >> d;
		adj[c1-'A'].push_back({c2-'A', d});
		adj[c2-'A'].push_back({c1-'A', d});
		v[c1-'A'] = c1;
		v[c2-'A'] = c2;
	}
	char x;
	int ans = 1e9;
	memset(vis, false, sizeof(vis));
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> q;
	q.push({0, 25});
	while (!q.empty()) {
		pair<int, int> k = q.top();
		q.pop();
		if (vis[k.second]) continue;
		vis[k.second] = true;
		if (k.second < 25) {
			if (ans > k.first) {
				ans = k.first;
				x = v[k.second];
			}
			break;
		}
		for (auto i: adj[k.second]) {
			q.push({i.second+k.first, i.first});
		}
	}
	cout << x << ' ' << ans << '\n';
}
