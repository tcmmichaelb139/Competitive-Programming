#include "bits/stdc++.h"
using namespace std;

struct TTT {
	char om;
	int i, j;
};

struct Node {
	int x, y;
	int px, py;
	int dist;

	bool operator<(const Node &rhs) const {
		return dist > rhs.dist;
	}
};

struct Board {
	vector<vector<char>> board;
	set<pair<int, int>> nxt;
	set<pair<int, int>> trash;
};

const int MAXN = 25;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const string MOO = "MOO";
const string OOM = "OOM";

int n;
string maze[MAXN][MAXN];
TTT ttt[MAXN][MAXN];
set<pair<int, int>> children[MAXN][MAXN];
bool vis[MAXN][MAXN];
map<vector<vector<char>>, bool> boardDone;
int ans = 0;

bool winning(vector<vector<char>> board) {
	auto testHor = [](vector<vector<char>> b, string s) {
		for (int i = 0; i < 3; i++)
			if (string() + b[i][0] + b[i][1] + b[i][2] == s)
				return true;
		return false;
	};
	auto testVert = [](vector<vector<char>> b, string s) {
		for (int i = 0; i < 3; i++)
			if (string() + b[0][i] + b[1][i] + b[2][i] == s)
				return true;
		return false;
	};
	auto testDiag = [](vector<vector<char>> b, string s) {
		return (string() + b[0][0] + b[1][1] + b[2][2] == s ||
		        string() + b[2][0] + b[1][1] + b[0][2] == s);
	};

	return testHor(board, MOO) || testHor(board, OOM) ||
	       testVert(board, MOO) || testVert(board, OOM) ||
	       testDiag(board, MOO) || testDiag(board, OOM);
}

void printBoard(Board cur) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << cur.board[i][j];
		cout << '\n';
	}
	for (auto i : cur.nxt)
		cout << i.first << ' ' << i.second << '\n';

	for (auto i : cur.trash)
		cout << "trash: " << i.first << ' ' << i.second << '\n';
}

void getAllChildren(Board &b, pair<int, int> cur) {
	if (b.trash.find(cur) != end(b.trash)) return;
	if (b.board[ttt[cur.first][cur.second].i][ttt[cur.first][cur.second].j] == '.') {
		b.nxt.insert(cur);
	} else {
		b.trash.insert(cur);
		for (auto nxt : children[cur.first][cur.second]) {
			getAllChildren(b, nxt);
		}
	}
}

void solve(Board cur) {
	/* printBoard(cur); */
	if (winning(cur.board)) {
		ans++;
		return;
	}
	for (auto xt : cur.nxt) {
		int i = ttt[xt.first][xt.second].i;
		int j = ttt[xt.first][xt.second].j;
		if (cur.board[i][j] == '.') {
			Board nxt = cur;
			nxt.board[i][j] = ttt[xt.first][xt.second].om;
			if (boardDone[nxt.board]) continue;
			boardDone[nxt.board] = true;
			nxt.nxt.erase(xt);
			nxt.trash.insert(xt);
			vector<pair<int, int>> era;
			for (auto x : nxt.nxt) {
				if (nxt.board[ttt[x.first][x.second].i][ttt[x.first][x.second].j] != '.') {
					era.push_back(x);
					getAllChildren(nxt, x);
				}
			}
			for (auto x : children[xt.first][xt.second]) {
				getAllChildren(nxt, x);
			}
			for (auto x : era) {
				nxt.nxt.erase(x);
				nxt.trash.insert(x);
			}
			solve(nxt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int si, sj;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 3 * n; j += 3) {
			if (s[j] == 'O' || s[j] == 'M') {
				ttt[i][j / 3] = {s[j], s[j + 1] - '1', s[j + 2] - '1'};
			} else if (s[j] == 'B') {
				si = i, sj = j / 3;
			}

			maze[i][j / 3] = s.substr(j, 3);
		}
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (maze[i][j][0] == '.' || maze[i][j][0] == '#') continue;
			memset(vis, false, sizeof vis);
			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({i, j});
			while (!q.empty()) {
				pair<int, int> v = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = v.first + dx[k], ny = v.second + dy[k];
					if (maze[nx][ny][0] == '#') continue;
					if (vis[nx][ny]) continue;
					vis[nx][ny] = true;
					if (maze[nx][ny][0] == 'O' || maze[nx][ny][0] == 'M') {
						children[i][j].insert({nx, ny});
					} else {
						q.push({nx, ny});
					}
				}
			}
		}
	}

	/* for (int i = 1; i < n - 1; i++) */
	/* 	for (int j = 1; j < n - 1; j++) { */
	/* 		cout << i << ' ' << j << '\n'; */
	/* 		for (auto k : children[i][j]) */
	/* 			cout << '\t' << k.first << ' ' << k.second << '\n'; */
	/* 	} */

	solve((Board){vector<vector<char>>(3, vector<char>(3, '.')), children[si][sj], {}});

	cout << ans << '\n';
}
