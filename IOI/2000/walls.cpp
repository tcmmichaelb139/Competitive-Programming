#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, l;
    cin >> m >> n >> l;
    vector<int> club(l);
    for (int i = 0; i < l; i++)
        cin >> club[i];

    vector<int> towns[n + 1];

    vector<vector<int>> regions(m);
    set<int> conn[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int a;
            cin >> a;
            regions[i].push_back(a);
            towns[a].push_back(i);
        }
        for (int a = 0; a < x; a++)
            conn[min(regions[i][a], regions[i][(a + 1) % x])][max(regions[i][a], regions[i][(a + 1) % x])].insert(i);
    }

    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));

    for (int i = 1; i <= n; i++) {
        queue<int> q;

        for (auto j : towns[i])
            q.push(j), dist[i][j] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int a = 0; a < regions[v].size(); a++) {
                for (auto b : conn[min(regions[v][a], regions[v][(a + 1) % regions[v].size()])][max(regions[v][a], regions[v][(a + 1) % regions[v].size()])]) {
                    if (dist[i][b] <= dist[i][v] + 1) continue;
                    dist[i][b] = dist[i][v] + 1;
                    q.push(b);
                }
            }
        }
    }

    int ans = 1e9;
    int place = 0;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (auto j : club)
            sum += dist[j][i];
        if (ans > sum) {
            ans = sum;
            place = i + 1;
        }
    }
    cout << ans << '\n';
    cout << place << '\n';
}
