/*
ID: tcmmich1
TASK: camelot
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct Node {
    int x, y;
    bool hasKing;
    int dist;

    bool operator<(const Node &rhs) const {
        return dist > rhs.dist;
    }
};

int dist[31][31][2];

int main() {
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    char ch;
    int x;
    cin >> ch >> x;
    pair<int, int> king = {ch - 'A', x - 1};
    vector<pair<int, int>> kni;
    while (cin >> ch >> x)
        kni.push_back({ch - 'A', x - 1});

    auto distKing = [&](int a, int b) { return max(abs(a - king.first), abs(b - king.second)); };

    int ans = 1e9;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int a = 0; a <= 30; a++)
                for (int b = 0; b <= 30; b++)
                    for (int c = 0; c < 2; c++)
                        dist[a][b][c] = 1e9;

            queue<Node> q;
            q.push({i, j, distKing(i, j) == 0, 0});

            while (!q.empty()) {
                Node v = q.front();
                q.pop();

                if (dist[v.x][v.y][v.hasKing] <= v.dist) continue;
                dist[v.x][v.y][v.hasKing] = v.dist;

                for (int a = 0; a < 8; a++) {
                    Node u = {v.x + dx[a], v.y + dy[a], v.hasKing, v.dist + 1};
                    if (u.x < 0 || u.y < 0 || u.x >= n || u.y >= m) continue;

                    q.push(u);

                    if (!v.hasKing && distKing(u.x, u.y) <= 2) {
                        u.hasKing = true;
                        u.dist += distKing(u.x, u.y);
                        q.push(u);
                    }
                }
            }

            int sum = 0;

            bool cont = false;
            for (int a = 0; a < (int)size(kni); a++) {
                if (dist[kni[a].first][kni[a].second][0] == (int)1e9 && dist[kni[a].first][kni[a].second][1] == (int)1e9) {
                    cont = true;
                    break;
                }
                if (dist[kni[a].first][kni[a].second][0] == (int)1e9) {
                    dist[kni[a].first][kni[a].second][0] = dist[kni[a].first][kni[a].second][1];
                }
                sum += dist[kni[a].first][kni[a].second][0];
            }

            if (cont) continue;

            ans = min(ans, sum + distKing(i, j));

            for (int a = 0; a < (int)size(kni); a++) {
                if (dist[kni[a].first][kni[a].second][1] == (int)1e9) continue;

                ans = min(ans, sum - dist[kni[a].first][kni[a].second][0] + dist[kni[a].first][kni[a].second][1]);
            }
        }
    }
    cout << ans << '\n';
}
