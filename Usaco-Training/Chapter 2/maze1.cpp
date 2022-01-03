/*
ID: tcmmich1
TASK: maze1
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int w, h;
bool ar[201][77];
bool vis[201][77];
int dist[201][77];
int dx[] = {0, 1, 0,-1}, dy[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	
	cin >> w >> h;
	vector<pair<int, int>> starts;
	for (int i = -1; i < 2*h+1; i++) {
		string s; getline(cin, s);
		if (i < 0) continue;
		for (int j = 0; j < 2*w+1; j++) {
			if ((i == 0 || i == 2*h) && s[j] == ' ')
				starts.push_back({i, j});
			if ((j == 0 || j == 2*w) && s[j] == ' ')
				starts.push_back({i, j});
			dist[i][j] = 1e9;
			if (s[j] == '-' || s[j] == '|' || s[j] == '+') {
				ar[i][j] = true;
				dist[i][j] = 0;
			}
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < starts.size(); i++) {
		q.push(starts[i]);
		dist[starts[i].first][starts[i].second] = 1;
		vis[starts[i].first][starts[i].second] = true;
	}
	while (!q.empty()) {
		pair<int, int> k = q.front();
		q.pop();
		for (int a = 0; a < 4; a++) {
			pair<int, int> x = {k.first+dx[a], k.second+dy[a]};
			if (x.first < 0 || x.first > 2*h || x.second < 0 || x.second > 2*w) continue;
			if (ar[x.first][x.second]) continue;
			if (!vis[x.first][x.second]) {
				vis[x.first][x.second] = true;
				dist[x.first][x.second] = min(dist[x.first][x.second], dist[k.first][k.second]+1);
				q.push(x);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 2*h+1; i++)
		for (int j = 0; j < 2*w+1; j++)
			ans = max(ans, dist[i][j]);
	cout << ans/2 << '\n';
}

