/*
ID: tcmmich1
TASK: ttwo
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

bool ar[10][10];
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};

bool turn(int x, int y) {
	if (x >= 0 && x <= 9 && y >= 0 && y <= 9) 
		if (!ar[x][y])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	
	pair<int, int> fjs, cows;
	for (int i = 0; i < 10; i++) {
		string s; cin >> s;
		for (int j = 0; j < 10; j++) {
			if (s[j] == '*') 
				ar[i][j] = true;
			if (s[j] == 'F')
				fjs = {i, j};
			if (s[j] == 'C')
				cows = {i, j};
		}
	}
	queue<pair<int, pair<pair<int, pair<int, int>>, pair<int, pair<int, int>>>>> q; //distance, cow, fj
	q.push({0, {{0, fjs}, {0, cows}}}); // 0 = up, 1 = right, 2 = 
	int a = 0;
	while (!q.empty()) {
		a++;
		if (a > 10000) break;
		pair<int, pair<int, int>> fjs = q.front().second.first, cows = q.front().second.second;
		int time = q.front().first;
		q.pop();
		if (fjs.second == cows.second) {
			cout << time << '\n';
			return 0;
		}
		if (turn(dx[fjs.first]+fjs.second.first, dy[fjs.first]+fjs.second.second))
			fjs.first = (fjs.first+1)%4;
		else {
			fjs.second.first += dx[fjs.first];
			fjs.second.second += dy[fjs.first];
		}
		if (turn(dx[cows.first]+cows.second.first, dy[cows.first]+cows.second.second))
			cows.first = (cows.first+1)%4;
		else {
			cows.second.first += dx[cows.first];
			cows.second.second += dy[cows.first];
		}
		q.push({time+1, {fjs, cows}});
	}
	cout << 0 << '\n';
}

