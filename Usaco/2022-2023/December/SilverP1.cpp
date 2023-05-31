#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200'001;

int n;
long long sum = 0;
long long extra[MAXN];
long long need[MAXN];
vector<int> adj[MAXN];
vector<pair<pair<int, int>, long long>> sol;

long long dfs(int v, int p) {
	for (auto u : adj[v]) {
		if (u == p) continue;
		long long k = dfs(u, v);
		if (k < 0) {
			if (extra[v] > 0) extra[v] += k;
			else need[v] -= k;
			if (extra[v] < 0) need[v] -= extra[v], extra[v] = 0;
		} else {
			if (need[v] > 0) need[v] -= k;
			else extra[v] += k;
			if (need[v] < 0) extra[v] -= need[v], need[v] = 0;
			if (k != 0) sol.push_back({{u, v}, k});
			extra[u] = need[u];
			need[u] = 0;
		}
	}
	return extra[v] - need[v];
}

void dfs2(int v, int p) {
	for (auto u : adj[v]) {
		if (u == p) continue;
		if (need[u] != 0)
			sol.push_back({{v, u}, need[u]});
		dfs2(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> extra[i];
		sum += extra[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	assert(sum % n == 0);

	sum /= n;

	for (int i = 1; i <= n; i++) {
		extra[i] -= sum;
		if (extra[i] < 0)
			need[i] = -extra[i], extra[i] = 0;
	}

	dfs(1, 0);
	dfs2(1, 0);

	cout << size(sol) << '\n';

	for (auto i : sol)
		cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
}
