#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    vector<pair<int, int>> mon;
    bool v[n][m];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') v[i][j] = true;
            else {
                if (s[j] == 'A') start = {i, j};
                v[i][j] = false;
                if (s[j] == 'M') {
                    mon.push_back({i, j});
                    v[i][j] = true;
                }
            }
        }
    }
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int dist[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            dist[i][j] = 1e9;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < mon.size(); i++) {
        q.push({mon[i], 0});
        dist[mon[i].first][mon[i].second] = 0;
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> k = q.front();
        q.pop();
        for (int a = 0; a < 4; a++) {
            pair<pair<int, int>, int> tmp = {{k.first.first+dx[a], k.first.second+dy[a]}, k.second+1};
            if (tmp.first.first < 0 || tmp.first.first >= n || tmp.first.second < 0 || tmp.first.second >= m) continue;
            if (v[tmp.first.first][tmp.first.second]) continue;
            if (dist[tmp.first.first][tmp.first.second] > tmp.second) {
                q.push(tmp);
                dist[tmp.first.first][tmp.first.second] = tmp.second;
            }
        }
    }
    pair<int, int> prev[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            prev[i][j] = {-1, -1};
    bool vis[n][m]; memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    vis[start.first][start.second] = true;
    q.push({start, 0});
    while (!q.empty()) {
        pair<pair<int, int>, int> k = q.front();
        q.pop();
        if (k.first.first == 0 || k.first.first == n-1 || k.first.second == 0 || k.first.second == m-1) {
            cout << "YES\n" << k.second << '\n';
            pair<int, int> p = k.first;
            string ans;
            for (pair<int, int> i = k.first; i.first != -1; i = prev[i.first][i.second]) {
                if (p == i) continue;
                if (p.first < i.first) ans += 'U';
                else if (p.first > i.first) ans += 'D';
                else if (p.second < i.second) ans += 'L';
                else if (p.second > i.second) ans += 'R';
                p = i;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
            return 0;
        }
        for (int a = 0; a < 4; a++) {
            pair<pair<int, int>, int> tmp = {{k.first.first+dx[a], k.first.second+dy[a]}, k.second+1};
            if (tmp.first.first < 0 || tmp.first.first >= n || tmp.first.second < 0 || tmp.first.second >= m) continue;
            if (v[tmp.first.first][tmp.first.second]) continue;
            if (vis[tmp.first.first][tmp.first.second]) continue;
            if (dist[tmp.first.first][tmp.first.second] <= tmp.second) continue;
            prev[tmp.first.first][tmp.first.second] = {k.first.first, k.first.second};
            vis[tmp.first.first][tmp.first.second] = true;
            q.push(tmp);
        }
    }
    cout << "NO\n";
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

