#include "bits/stdc++.h"
using namespace std;

struct node {
    int i1, j1, i2, j2;
};

const int MAXN = 21;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

char ar[MAXN][MAXN];
bool vis[MAXN][MAXN];

void ff(int x, int y, int mnx, int mny, int mxx, int mxy) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < mnx || ny < mny || nx > mxx || ny > mxy) continue;
        if (ar[x][y] != ar[nx][ny]) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        ff(nx, ny, mnx, mny, mxx, mxy);
    }
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> ar[i][j];

    vector<node> ans;
    for (int h = n - 1; h >= 0; h--) {
        for (int w = n - 1; w >= 0; w--) {
            for (int i = 0; i < n; i++) {
                if (i + h >= n) continue;
                for (int j = 0; j < n; j++) {
                    if (j + w >= n) continue;
                    int ei = i + h, ej = j + w;
                    bool ok = true;
                    for (auto k : ans)
                        if (k.i1 <= i && k.j1 <= j && k.i2 >= ei && k.j2 >= ej) {
                            ok = false;
                            break;
                        }
                    if (!ok) continue;
                    memset(vis, false, sizeof vis);
                    map<char, int> m;
                    for (int a = i; a <= ei; a++) {
                        for (int b = j; b <= ej; b++) {
                            if (vis[a][b]) continue;
                            vis[a][b] = true;
                            ff(a, b, i, j, ei, ej);
                            m[ar[a][b]]++;
                        }
                    }
                    bool one = false;
                    bool gtwo = false;
                    for (auto a : m) {
                        if (a.second == 1)
                            one = true;
                        if (a.second >= 2)
                            gtwo = true;
                    }
                    if (one && gtwo && m.size() == 2)
                        ans.push_back({i, j, ei, ej});
                }
            }
        }
    }
    /* for (auto i : ans) */
    /*     cout << i.i1 << ' ' << i.j1 << ' ' << i.i2 << ' ' << i.j2 << '\n'; */
    cout << ans.size() << '\n';
}
