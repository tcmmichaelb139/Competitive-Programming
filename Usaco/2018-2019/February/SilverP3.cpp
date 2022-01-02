#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, bool>> adj[200001]; //index and if they are the same
int val[200001];
bool vis[200001];
bool imp;

void dfs(int k, int x) {
	if (imp) return;
	for (auto i: adj[k]) {
		if (vis[i.first]) {
			if (i.second && x != val[i.first])
				imp = true;
			else if (!i.second && x == val[i.first])
				imp = true;
		} else {
			vis[i.first] = true;
			if (i.second) 
				val[i.first] = x;
			else 
				val[i.first] = !x;
			dfs(i.first, val[i.first]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char c; int a, b; cin >> c >> a >> b;
		if (c == 'S') {
			adj[a].push_back({b, true});
			adj[b].push_back({a, true});
		} else {
			adj[a].push_back({b, false});
			adj[b].push_back({a, false});
		}
	}
	string times = "1";
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i, 0);
		times += '0';
	}
	if (imp) cout << 0 << '\n';
	else cout << times << '\n';
}

