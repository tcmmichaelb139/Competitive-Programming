#include "bits/stdc++.h"
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<vector<char>> ar(n, vector<char>(n));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 'M')
                start = {i, j};
            else if (ar[i][j] == 'D')
                end = {i, j};
        }

    auto bee_dist_gen = [&]() {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ar[i][j] == 'H')
                    q.push({i, j}), dist[i][j] = 0;

        while (!q.empty()) {
            pair<int, int> v = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = v.first + dx[i], ny = v.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (ar[nx][ny] == 'T' || ar[nx][ny] == 'D') continue;
                if (dist[nx][ny] <= dist[v.first][v.second] + 1) continue;

                dist[nx][ny] = dist[v.first][v.second] + 1;
                q.push({nx, ny});
            }
        }

        return dist;
    };

    vector<vector<int>> bee_dist = bee_dist_gen();

    auto test_honey = [&](int honey) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[start.first][start.second] = 0;

        queue<pair<int, int>> q;
        q.push(start);
        while (!q.empty()) {
            pair<int, int> v = q.front();
            q.pop();

            if (bee_dist[v.first][v.second] <= honey + dist[v.first][v.second] / s) continue;

            if (end == v) return true;

            for (int i = 0; i < 4; i++) {
                int nx = v.first + dx[i], ny = v.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (ar[nx][ny] == 'T') continue;
                if (dist[nx][ny] <= dist[v.first][v.second] + 1) continue;

                dist[nx][ny] = dist[v.first][v.second] + 1;

                q.push({nx, ny});
            }
        }
        return false;
    };

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (test_honey(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (test_honey(l))
        cout << l << '\n';
    else
        cout << -1 << '\n';
}
