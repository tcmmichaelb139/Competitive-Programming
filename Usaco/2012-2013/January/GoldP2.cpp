#include "bits/stdc++.h"
using namespace std;

const int MAXN = 51;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct node {
    int x, y;
    int dist;
    int orig;
};

int n, m;
string ar[MAXN];
int val[MAXN][MAXN];
bool vis[MAXN][MAXN];
map<pair<int, int>, int> edges;
vector<pair<int, int>> adj[MAXN];

void ff(int x, int y, int va) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y]) return;
    if (ar[x][y] != 'X') return;
    vis[x][y] = true;
    val[x][y] = va;
    for (int i = 0; i < 4; i++)
        if (!vis[x + dx[i]][y + dy[i]])
            ff(x + dx[i], y + dy[i], va);
}

int main() {
    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int cur = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (ar[i][j] == 'X')
                ff(i, j, cur++);
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ar[i][j] != 'X') continue;

            memset(vis, false, sizeof vis);

            queue<node> q;
            q.push({i, j, 0, val[i][j]});

            while (!q.empty()) {
                node v = q.front();
                q.pop();

                for (int a = 0; a < 4; a++) {
                    int nx = v.x + dx[a], ny = v.y + dy[a];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (ar[nx][ny] == '.') continue;
                    if (ar[nx][ny] == 'X') {
                        if (v.orig != val[nx][ny]) {
                            pair<int, int> p = {min(v.orig, val[nx][ny]), max(v.orig, val[nx][ny])};
                            if (edges.find(p) == edges.end())
                                edges[p] = v.dist;
                            else
                                edges[p] = min(edges[p], v.dist);
                        }
                    }
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny, v.dist + (ar[nx][ny] == 'S'), v.orig});
                }
            }
        }
    }

    for (auto i : edges) {
        adj[i.first.first].push_back({i.first.second, i.second});
        adj[i.first.second].push_back({i.first.first, i.second});
    }

    int dp[1 << cur][cur];

    for (int i = 0; i < 1 << cur; i++)
        for (int j = 0; j < cur; j++)
            dp[i][j] = 1e9;
    for (int i = 0; i < cur; i++)
        dp[1 << i][i] = 0;

    for (int i = 0; i < 1 << cur; i++) {
        for (int j = 0; j < cur; j++) {
            for (auto a : adj[j]) {
                dp[i | (1 << a.first)][a.first] = min(dp[i | (1 << a.first)][a.first], dp[i][j] + a.second);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < cur; i++)
        ans = min(ans, dp[(1 << cur) - 1][i]);
    cout << ans << '\n';
}
