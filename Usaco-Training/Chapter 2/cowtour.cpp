/*
ID: tcmmich1
TASK: cowtour
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n;
pair<double, double> ar[150];
bool con[150][150];
int comp[150];
bool vis[150];
double farth[150];
double d[150][150];

void dfs(int k, int val) {
	for (int i = 0; i < n; i++) {
		if (!vis[i] && con[k][i]) {
			vis[i] = true;
			comp[i] = val;
			dfs(i, val);
		}
	}
}

double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			con[i][j] = s[j]-'0';
			if (con[i][j])
				d[i][j] = dist(ar[i], ar[j]);
			else 
				d[i][j] = 1e18;
			if (i == j) d[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		comp[i] = i;
		dfs(i, i);
	}
	for (int k = 0; k < n; k++) 
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				d[a][b] = min(d[a][b], d[a][k]+d[k][b]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (comp[i] == comp[j])
				farth[comp[i]] = max(farth[comp[i]], d[i][j]);
	double shortest = 1e18;
	for (int a = 0; a < n; a++) {
		double farthesta = 0;
		for (int j = 0; j < n; j++) 
			if (comp[a] == comp[j])
				farthesta = max(farthesta, d[a][j]);
		for (int b = 0; b < n; b++) {
			double farthestb = 0;
			for (int i = 0; i < n; i++)
				if (comp[b] == comp[i])
					farthestb = max(farthestb, d[b][i]);
			if (comp[a] != comp[b])
				shortest = min(shortest, max(farthesta+farthestb+dist(ar[a], ar[b]), max(farth[comp[a]], farth[comp[b]])));
		}
	}
	cout << fixed << setprecision(6) << shortest << '\n';
}
