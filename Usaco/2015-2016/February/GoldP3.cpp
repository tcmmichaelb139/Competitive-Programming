// gets 6/10 testcases
#include<bits/stdc++.h>
using namespace std;

int a, b, n, m;
vector<int> x, y;
vector<pair<int, int>> points;
vector<pair<int, pair<pair<int, int>, pair<int, int>>>> v, v2;
map<pair<int, int>, int> p;

struct DSU {
	vector<int> v;
	void init(int mxn) { v.assign(mxn, -1); }
	int get(int e) { return (v[e] < 0 ? e : get(v[e])); }
	bool unite(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		if (v[a] > v[b]) swap(a, b);
		v[a] += v[b]; v[b] = a;
		return true;
	}
};

int main() {
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> n >> m;
	x.push_back(0), x.push_back(a);
	y.push_back(0), y.push_back(b);
	for (int i = 0; i < n; i++) {
		int e; cin >> e;
		x.push_back(e);
	}
	for (int i = 0; i < m; i++) {
		int e; cin >> e;
		y.push_back(e);
	}
	int point = 0;
	for (int i = 0; i < x.size(); i++) 
		for (int j = 0; j < y.size(); j++) {
			points.push_back({x[i], y[j]});
			p[{x[i], y[j]}] = point;
			point++;
		}
	sort(begin(points), end(points));
	for (int i = 0; i < points.size()-1; i++) {
		if (points[i].first == points[i+1].first && points[i].first != 0 && points[i].first != a) 
			v.push_back({points[i+1].second-points[i].second, {points[i], points[i+1]}});
		else 
			v2.push_back({points[i+1].second-points[i].second, {points[i], points[i+1]}});
	}
	sort(begin(points), end(points), [](const pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second < b.second;
			});
	for (int i = 0; i < points.size()-1; i++) {
		if (points[i].second == points[i+1].second && points[i].second != 0 && points[i].second != b) 
			v.push_back({points[i+1].first-points[i].first, {points[i], points[i+1]}});
		else 
			v2.push_back({points[i+1].first-points[i].first, {points[i], points[i+1]}});
	}
	sort(rbegin(v), rend(v));
	DSU dsu; dsu.init(point);
	long long ans = 0;
	for (int i = 0; i < v2.size(); i++) 
		dsu.unite(p[v2[i].second.first], p[v2[i].second.second]);
	for (int i = 0; i < v.size(); i++) {
		if (!dsu.unite(p[v[i].second.first], p[v[i].second.second])) {
			ans += v[i].first;
		}
	}
	cout << ans << '\n';
}
