#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int val = 0;
vector<int> adj[100001];
int vis[100001];

void dfs(int k) {
	for (auto i: adj[k]) {
		if (vis[i]) continue;
		if (s[i-1] != s[k-1]) continue;
		vis[i] = val;
		dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	cin >> n >> m >> s;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i <= n; i++)
		if (!vis[i]) {
			val++;
			vis[i] = val;
			dfs(i);
		}
	vector<bool> f(m, false);
	for (int i = 0; i < m; i++) {
		int a, b; char c; cin >> a >> b >> c;
		if (s[a-1] == c || vis[a] != vis[b]) f[i] = true;
		else f[i] = false;
	}
	for (int i = 0; i < m; i++) 
		cout << f[i];
	cout << '\n';
}
