#include<bits/stdc++.h>
using namespace std;

int n, c; 
int mx, my;
char f[2001][2001];
bool vis[2001][2001];
vector<pair<pair<int, int>, pair<int, int>>> fence;
vector<pair<int, int>> cow;
map<int, int> x, y;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int ff(int i, int j) {
	if (i < 0 || j < 0 || i > mx || j > my) return 0;
	if (vis[i][j]) return 0;
	if (f[i][j] == 'f') return 0;
	vis[i][j] = true;
	int ans = 0;
	if (f[i][j] == 'c') ans++;
	for (int a = 0; a < 4; a++) 
		ans += ff(i+dx[a], j+dy[a]);
	return ans;
}

int main() {
	freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> c;
	set<int> sx, sy;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		fence.push_back({{a, b}, {c, d}});
		sx.insert(a), sx.insert(c);
		sy.insert(b), sy.insert(d);
	}
	for (int i = 0; i < c; i++) {
		int a, b; cin >> a >> b;
		cow.push_back({a, b});
		sx.insert(a);
		sy.insert(b);
	}
	int tmp = 1;
	for (auto i: sx) {
		x[i] = tmp;
		tmp += 2;
	}
	mx = tmp+1;
	sx.clear();
	tmp = 1;
	for (auto i: sy) {
		y[i] = tmp;
		tmp += 2;
	}
	my = tmp+1;
	sy.clear();
	for (int i = 0; i < n; i++) {
		if (fence[i].first.first != fence[i].second.first) {
			if (fence[i].first.first > fence[i].second.first) swap(fence[i].first.first, fence[i].second.first);
			for (int j = x[fence[i].first.first]; j <= x[fence[i].second.first]; j++) 
				f[j][y[fence[i].first.second]] = 'f';
		} else {
			if (fence[i].first.second > fence[i].second.second) swap(fence[i].first.second, fence[i].second.second);
			for (int j = y[fence[i].first.second]; j <= y[fence[i].second.second]; j++) 
				f[x[fence[i].first.first]][j]= 'f';
		}
	}
	for (int i = 0; i < c; i++) 
		f[x[cow[i].first]][y[cow[i].second]] = 'c';
	int ans = 0;
	for (auto i: cow) {
		if (!vis[x[i.first]][y[i.second]])
			ans = max(ans, ff(x[i.first], y[i.second]));
	}
	cout << ans << '\n';
}

