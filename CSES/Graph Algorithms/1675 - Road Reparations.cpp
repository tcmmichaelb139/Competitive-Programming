#include<bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> v; 
	int tmp = 0;
	void init(int n) { v = vector<int>(n, -1); }
	int get(int e) { return (v[e] < 0 ? e : get(v[e])); }
	bool comp() { return tmp == v.size()-2; }
	bool unite(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		if (v[a] > v[b]) swap(a, b);
		tmp++;
		v[a] += v[b]; v[b] = a; return true;
	}
};

int n, m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	DSU dsu; dsu.init(n+1);
	vector<pair<long long, pair<int, int>>> v(m);
	for (int i = 0; i < m; i++) 
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
	sort(begin(v), end(v));
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		if (dsu.unite(v[i].second.first, v[i].second.second))
			ans += v[i].first;
	}
	if (dsu.comp())
		cout << ans << '\n';
	else 
		cout << "IMPOSSIBLE\n";
}
