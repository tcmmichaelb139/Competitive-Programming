#include<bits/stdc++.h>
using namespace std;

int n; 
bool hay[21][21];
pair<int, int> dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool vis[21][21][21][21][21][21];

struct point {
    int dist;
    int x1, y1;
    int dir1;
    int x2, y2;
    int dir2;
};

int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == 'H') hay[i][j] = true;
    }
    queue<point> q;
    vis[0][n-1][0][0][n-1][1] = true;
    q.push({0, n-1, 0, 0, n-1, 0, 1});
    while (!q.empty()) {
        point k = q.front();
        q.pop();
        /* cout << k.dist << ' ' << k.x1 << ' ' << k.y1 << ' ' << k.dir1 << ' ' << k.x2 << ' ' << k.y2 << ' ' << k.dir2 << '\n';; */
        if (k.x1 == 0 && k.x2 == 0 && k.y1 == n-1 && k.y2 == n-1) {
            cout << k.dist << '\n';
            return 0;
        }
        k.dist++;
        point p = k;
        if (p.x1 != 0 || p.y1 != n-1) {
            if (p.x1+dir[p.dir1].first >= 0 && p.x1+dir[p.dir1].first < n
                && p.y1+dir[p.dir1].second >= 0 && p.y1+dir[p.dir1].second < n
                && !hay[p.x1+dir[p.dir1].first][p.y1+dir[p.dir1].second]) {
                p.x1 += dir[p.dir1].first;
                p.y1 += dir[p.dir1].second;
            }
        }
        if (p.x2 != 0 || p.y2 != n-1) {
            if (p.x2+dir[p.dir2].first >= 0 && p.x2+dir[p.dir2].first < n
                && p.y2+dir[p.dir2].second >= 0 && p.y2+dir[p.dir2].second < n
                && !hay[p.x2+dir[p.dir2].first][p.y2+dir[p.dir2].second]) {
                p.x2 += dir[p.dir2].first;
                p.y2 += dir[p.dir2].second;
            }
        }
        if (!vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2]) {
            vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2] = true;
            q.push(p);
        }
        p = k;
        p.dir1 = (p.dir1+3)%4;
        p.dir2 = (p.dir2+3)%4;
        if (!vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2]) {
            vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2] = true;
            q.push(p);
        }
        p = k;
        p.dir1 = (p.dir1+5)%4;
        p.dir2 = (p.dir2+5)%4;
        if (!vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2]) {
            vis[p.x1][p.y1][p.dir1][p.x2][p.y2][p.dir2] = true;
            q.push(p);
        }
    }
}

