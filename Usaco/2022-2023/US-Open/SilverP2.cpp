#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c, n;
	cin >> c >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
			if (s[j] == 'G')
				v[i] |= 1 << j;
	}

	queue<int> q;
	vector<int> dist(1 << c, -1);
	for (int i = 0; i < n; i++)
		dist[v[i]] = 0, q.push(v[i]);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < c; i++) {
			int nu = u ^ (1 << i);
			if (dist[nu] != -1) continue;
			dist[nu] = dist[u] + 1;
			q.push(nu);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << c - dist[(1 << c) - 1 ^ v[i]] << '\n';
	}
}
