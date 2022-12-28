#include "bits/stdc++.h"
using namespace std;

const int MAXN = 30;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, a, b;
bool ar[MAXN][MAXN];

long long dijkstra(pair<int, int> start) {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> q;
    bool vis[MAXN][MAXN];
    memset(vis, false, sizeof vis);
    long long far = 0;

    q.push({0, {start}});
    while (!q.empty()) {
        pair<int, pair<int, int>> v = q.top();
        q.pop();

        if (vis[v.second.first][v.second.second]) continue;
        vis[v.second.first][v.second.second] = true;
        far = v.first;

        for (int i = 0; i < 4; i++) {
            int ux = v.second.first + dx[i];
            int uy = v.second.second + dy[i];

            if (ux < 0 || uy < 0 || ux >= n || uy >= n) continue;
            if (ar[v.second.first][v.second.second] != ar[ux][uy])
                q.push({v.first + b, {ux, uy}});
            else
                q.push({v.first + a, {ux, uy}});
        }
    }
    return far;
}

int main() {
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '(')
                ar[i][j] = 0;
            else
                ar[i][j] = 1;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dijkstra({i, j}));
    cout << ans << '\n';
}
