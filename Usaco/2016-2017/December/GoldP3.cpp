#include<bits/stdc++.h>
using namespace std;

int n, xl, yl, xb, yb;
vector<pair<int, int>> x[100001], y[100001];
pair<int, int> v[100001];
map<pair<int, int>, bool> vis;
map<int, int> mx, my;
set<int> sx, sy;

int main() {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> xl >> yl >> xb >> yb;
	sx.insert(xl), sx.insert(xb);
	sy.insert(yl), sy.insert(yb);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		sx.insert(v[i].first);
		sy.insert(v[i].second);
	}
	int ind = 0;
	for (auto i: sx)
		mx[i] = ind, ind++;
	ind = 0;
	for (auto i: sy)
		my[i] = ind, ind++;
	for (int i = 0; i < n; i++) {
		x[mx[v[i].first]].push_back({mx[v[i].first], my[v[i].second]});
		y[my[v[i].second]].push_back({mx[v[i].first], my[v[i].second]});
	}
	xl = mx[xl], yl = my[yl];
	xb = mx[xb], yb = my[yb];
	x[xb].push_back({xb, yb});
	y[yb].push_back({xb, yb});
	//dist, direction, x, y
	queue<pair<pair<int, int>, pair<int, int>>> q; // 0 horizontal & 1 is vertical
	vis[{xl, yl}] = true;
	q.push({{0, 0}, {xl, yl}});
	q.push({{0, 1}, {xl, yl}});
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> k = q.front();
		q.pop();
		if (k.second.first == xb  && k.second.second == yb) {
			cout << k.first.first-1 << '\n';
			return 0;
		}
		if (k.first.second) {
			for (auto i: y[k.second.second])
				if (!vis[i]) {
					vis[i] = true;
					q.push({{k.first.first+1, false}, i});
				}
		} else {
			for (auto i: x[k.second.first])
				if (!vis[i]) {
					vis[i] = true;
					q.push({{k.first.first+1, true}, i});
				}
		}
	}
}
