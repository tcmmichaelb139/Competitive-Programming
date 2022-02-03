#include<bits/stdc++.h>
using namespace std;

int n, d; 
vector<pair<int, int>> b, e;
vector<pair<int, bool>> z;
int dist[100001];
bool visb[100001], vise[100001];

int main() {
	/* freopen("piepie.in", "r", stdin); */
	/* freopen("piepie.out", "w", stdout); */
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		b.push_back({x, y});
		if (y == 0) z.push_back({i, false});
		dist[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		e.push_back({x, y});
		if (x == 0) z.push_back({i, true});
	}
	queue<pair<int, pair<int, bool>>> q;
	for (int i = 0; i < z.size(); i++) 
		q.push({1, z[i]});
	while (!q.empty()) {
		pair<int, pair<int, int>> k = q.front();
		q.pop();
		if (!k.second.second)
			cout << k.first << ' ' << b[k.second.first].first << ' ' << b[k.second.first].second << '\n';
		if (k.second.second && vise[k.second.first]) continue;
		if (!k.second.second && visb[k.second.first]) continue;
		if (k.second.second) vise[k.second.first] = true;
		if (!k.second.second) visb[k.second.first] = true;
		if (!k.second.second)
			dist[k.second.first] = k.first;
		if (k.second.second) {
			for (int i = 0; i < n; i++)
				if (b[i].second <= e[k.second.first].second && b[i].second >= e[k.second.first].second-d)
					q.push({k.first+1, {i, false}});
		} else {
			for (int i = 0; i < n; i++)
				if (e[i].first <= b[k.second.first].first && e[i].first >= b[k.second.first].first-d)
					q.push({k.first+1, {i, true}});
		}
	}
	for (int i = 0; i < n; i++) 
		cout << dist[i] << '\n';
}
