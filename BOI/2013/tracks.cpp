#include "bits/stdc++.h"
using namespace std;

const int MAXN = 4001;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n, m;
char ar[MAXN][MAXN];
bool vis[MAXN][MAXN];
char cur;
queue<pair<int, int>> qcur;
queue<pair<int, int>> qnext;

void dfs(queue<pair<int, int>> q) {
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        if (vis[v.first][v.second]) continue;
        vis[v.first][v.second] = true;

        for (int i = 0; i < 4; i++) {
            pair<int, int> u = {v.first + dx[i], v.second + dy[i]};
            if (u.first < 0 || u.second < 0 || u.first >= n || u.second >= m) continue;
            if (ar[u.first][u.second] == '.') continue;
            if (vis[u.first][u.second]) continue;
            if (ar[u.first][u.second] == cur)
                q.push(u);
            else
                qnext.push(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];

    int ans = 0;
    qcur.push({0, 0});
    cur = ar[0][0];
    while (!qcur.empty()) {
        queue<pair<int, int>> qtmp = qnext;
        while (!qnext.empty()) qnext.pop();
        cur = ar[qcur.front().first][qcur.front().second];
        dfs(qcur);
        qcur = qnext;
        ans++;
    }
    cout << ans << '\n';
}
