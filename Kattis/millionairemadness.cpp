#include "bits/stdc++.h"
using namespace std;

struct node {
    int lad;
    int x;
    int y;

    bool operator<(const node& rhs) const {
        return lad > rhs.lad;
    }
};

const int dx[] = {1, 0, -1, 0},
          dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    priority_queue<node> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        node v = q.top();
        q.pop();

        if (v.x == n - 1 && v.y == m - 1) {
            cout << v.lad << '\n';
            break;
        }

        if (vis[v.x][v.y]) continue;
        vis[v.x][v.y] = true;

        for (int a = 0; a < 4; a++) {
            node u = {v.lad, v.x + dx[a], v.y + dy[a]};

            if (u.x < 0 || u.y < 0 || u.x >= n || u.y >= m) continue;

            int diff = ar[u.x][u.y] - ar[v.x][v.y];

            u.lad = max(u.lad, diff);

            q.push(u);
        }
    }
}
