#include<bits/stdc++.h>
using namespace std;

int n, m;
int ar[1000][1000];
int dist[1000][1000][2];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool cmp(pair<int, int> a) {
    if (a.first < 0 || a.first >= n || a.second < 0 || a.second >= m) 
        return true;
    return false;
}

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> ar[i][j], dist[i][j][0] = dist[i][j][1] = 1e9;
    priority_queue<pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>> q;
    dist[0][0][0] = 0;
    q.push({{0, 0}, 0});
    while (!q.empty()) {
        pair<pair<int, int>, int> k = q.top();
        q.pop();
        if (k.first.first == n-1 && k.first.second == m-1) {
            cout << dist[k.first.first][k.first.second][k.second] << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            pair<pair<int, int>, int> x = k;
            x.first.first += dx[i];
            x.first.second += dy[i];
            if (cmp(x.first)) 
                continue;
            if (ar[x.first.first][x.first.second] == 3 && !x.second)
                continue;
            if (ar[x.first.first][x.first.second] == 0) 
                continue;
            int add = 1;
            if (ar[x.first.first][x.first.second] == 4) {
                while (!cmp({x.first.first+dx[i], x.first.second+dy[i]}) 
                        && ar[x.first.first][x.first.second] == 4 
                        && ar[x.first.first+dx[i]][x.first.second+dy[i]] != 0
                        && (ar[x.first.first+dx[i]][x.first.second+dy[i]] != 3 || x.second)) {
                    x.first.first += dx[i], x.first.second += dy[i], add++;
                }
                x.second = 0;
            }
            if (ar[x.first.first][x.first.second] == 2) 
                x.second = 1;
            if (dist[x.first.first][x.first.second][x.second] > dist[k.first.first][k.first.second][k.second]+add) {
                /* vis[x.first.first][x.first.second][x.second] = true; */
                dist[x.first.first][x.first.second][x.second] = dist[k.first.first][k.first.second][k.second]+add;
                q.push(x);
            }
        }
    }
    cout << -1 << '\n';
}

