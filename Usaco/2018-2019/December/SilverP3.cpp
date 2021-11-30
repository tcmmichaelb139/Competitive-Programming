#include <bits/stdc++.h>
using namespace std;

int n, k;
int ar[100][10];
bool vis[100][10];
bool vis2[100][10];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int ff(int i, int j, int x, bool del) {
	if (i < 0 || j < 0 || i >= n || j >= 10) return 0;
	if (vis2[i][j]) return 0;
	if (ar[i][j] != x) return 0;
	if (del) ar[i][j] = 0;
	vis2[i][j] = true;
	vis[i][j] = true;
	int y = 1;
	for (int a = 0; a < 4; a++) {
		y += ff(i+dx[a], j+dy[a], x, del);
	}
	return y;
}

bool fix() {
	bool did = false;
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (ar[i][j] != 0) {
				int x = -1;
				for (int a = i+1; a < n; a++)
					if (ar[a][j] == 0)
						x = a;
				if (x != i && x != -1) {
					did = true;
					ar[x][j] = ar[i][j];
					ar[i][j] = 0;
				}
			}
		}
	}
	return did;
}

int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 10; j++) {
			ar[i][j] = s[j]-'0';
		}
	}
	bool prev = false;
	while(true) {
		if (!fix()) {
			if (prev)
				break;
			else 
				prev = true;
		} else prev = false;
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				int num = 0;
				if (!vis[i][j] && ar[i][j] != 0) {
 					memset(vis2, false, sizeof(vis2));
					num = ff(i, j, ar[i][j], false);
					/* cout << i << ' ' << j << ' ' << ar[i][j] << '\n'; */
				}
				/* cout << ar[i][j] << ' ' << num << '\n'; */
				if (num >= k) {
					memset(vis2, false, sizeof(vis2));
					ff(i, j, ar[i][j], true);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) 
			cout << ar[i][j];
		cout << '\n';
	}
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

