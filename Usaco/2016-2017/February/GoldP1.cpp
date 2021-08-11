#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out","w",stdout);

    int n, t;
    cin >> n >> t;
    int v[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    int dist[n][n][3]; 
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int a = 0; a < 3; a++) dist[i][j][a] = 1e9;
    priority_queue<pair<pair<int, int>, pair<int, int>>,
        vector<pair<pair<int, int>, pair<int, int>>>,
        greater<pair<pair<int, int>, pair<int, int>>>> q; // <currdist, numcross><x, y>
    q.push({{0, 0}, {0, 0}});
    while (!q.empty()) {
        pair<pair<int, int>, pair<int, int>> k = q.top();
        q.pop();
        if (k.second.first < 0 || k.second.first >= n) continue;
        if (k.second.second < 0 || k.second.second >= n) continue;
        if (dist[k.second.first][k.second.second][k.first.second] != 1e9) continue;
        dist[k.second.first][k.second.second][k.first.second] = k.first.first;
        if (k.first.second == 0 && (k.second.first != 0 || k.second.second != 0))
            dist[k.second.first][k.second.second][k.first.second] += v[k.second.first][k.second.second];
        for (int i = 0; i < 4; i++) 
            q.push({{dist[k.second.first][k.second.second][k.first.second]+t, (k.first.second+1)%3},
                    {k.second.first+dx[i], k.second.second+dy[i]}});
    }
    cout << min(dist[n-1][n-1][0], min(dist[n-1][n-1][1], dist[n-1][n-1][2])) << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
