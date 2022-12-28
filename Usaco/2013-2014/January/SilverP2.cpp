#include "bits/stdc++.h"
using namespace std;

const int MAXN = 501;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n, m;
int ar[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y, int d) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
        if (abs(ar[nx][ny] - ar[x][y]) > d) continue;
        vis[nx][ny] = true;
        dfs(nx, ny, d);
    }
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];

    vector<pair<int, int>> wp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a)
                wp.push_back({i, j});
        }

    int l = 0, r = 1e9;
    while (l < r) {
        memset(vis, 0, sizeof(vis));
        int mid = l + (r - l) / 2;

        vis[wp[0].first][wp[0].second] = true;
        dfs(wp[0].first, wp[0].second, mid);

        bool ok = true;
        for (auto i : wp)
            if (!vis[i.first][i.second])
                ok = false;

        if (ok)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
