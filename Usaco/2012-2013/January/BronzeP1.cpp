#include<bits/stdc++.h>
using namespace std;

int n, a, b;
map<int, int> x, y;
char ar[202][202];
int breako = 0;
pair<int, int> start;

bool dfs(int i, int j, int diri, int dirj) {
	if (breako > 100000) return false;
	if (i < 0 || j < 0 || i > 201 || j > 201) return false;
	if (ar[i][j] == 'B') return true;
	breako++;
	if (ar[i][j] == '/') {
		if (diri == 1)
			diri = 0, dirj = -1;
		else if (diri == -1)
			diri = 0, dirj = 1;
		else if (dirj == 1) 
			diri = -1, dirj = 0;
		else 
			diri = 1, dirj = 0;
	} else if (ar[i][j] == '\\') {
		if (diri == 1)
			diri = 0, dirj = 1;
		else if (diri == -1)
			diri = 0, dirj = -1;
		else if (dirj == 1) 
			diri = 1, dirj = 0;
		else 
			diri = -1, dirj = 0;
	}
	return dfs(i+diri, j+dirj, diri, dirj);
}

int main() {
	freopen("mirrors.in", "r", stdin);
	freopen("mirrors.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b;
	vector<pair<pair<int, int>, char>> v;
	set<int> sx, sy;
	for (int i = 0; i < n; i++) {
		int e, d; char c;
		cin >> e >> d >> c;
		if (c == '/') c = '\\';
		else c = '/';
		v.push_back({{e, d}, c});
		sx.insert(e), sy.insert(d);
	}
	sx.insert(0), sy.insert(0);
	sx.insert(a), sy.insert(b);
	int tmp = 0;
	for (auto i: sx) {
		if (i == 0) 
			start.first = tmp;
		x[i] = tmp;
		tmp++;
	}
	tmp = 0;
	for (auto i: sy) {
		if (i == 0) 
			start.second = tmp;
		y[i] = tmp;
		tmp++;
	}
	for (int i = 0; i <= 201; i++)
		for (int j = 0; j <= 201; j++) 
			ar[i][j] = '.';
	for (int i = 0; i < n; i++) {
		ar[x[v[i].first.first]][y[v[i].first.second]] = v[i].second;
	}
	ar[x[a]][y[b]] = 'B';
	if (dfs(start.first, start.second, 1, 0)) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (ar[x[v[i].first.first]][y[v[i].first.second]] == '/') 
			ar[x[v[i].first.first]][y[v[i].first.second]] = '\\';
		else 
			ar[x[v[i].first.first]][y[v[i].first.second]] = '/';
		breako = 0;
		if (dfs(start.first, start.second, 1, 0)) {
			cout << i+1 << '\n';
			return 0;
		}
		if (ar[x[v[i].first.first]][y[v[i].first.second]] == '/') 
			ar[x[v[i].first.first]][y[v[i].first.second]] = '\\';
		else 
			ar[x[v[i].first.first]][y[v[i].first.second]] = '/';
	}
	cout << -1 << '\n';
}
