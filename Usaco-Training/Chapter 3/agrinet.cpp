/*
ID: tcmmich1
TASK: agrinet
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> adj[100];
bool vis[100];
int dist[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			adj[i].push_back({a, j});
		}
	for (int i = 0; i < n; i++) dist[i] = 1e9;
	int ans = 0;
	dist[0] = 0;
	for (int i = 0; i < n; i++) {
		int k = -1;
		for (int j = 0; j < n; j++)
			if (!vis[j] && (k == -1 || dist[j] < dist[k]))
				k = j;
		ans += dist[k];
		vis[k] = true;
		for (auto i: adj[k])
			dist[i.second] = min(dist[i.second], i.first);
	}
	cout << ans << '\n';
}
