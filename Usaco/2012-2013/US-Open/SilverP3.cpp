#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> lr(m);
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        lr[i] = (c == 'L' ? 1 : 0);
    }

    vector<vector<long long>> vis(n + 1, vector<long long>(m + 1, -1));
    vector<long long> dist;

    long long total = 0;
    pair<int, int> cur = {1, 0};
    while (vis[cur.first][cur.second] == -1) {
        vis[cur.first][cur.second] = total;
        dist.push_back(cur.first);

        cur.first = (lr[cur.second] ? v[cur.first - 1].first : v[cur.first - 1].second);
        cur.second = (cur.second + 1) % m;
        total++;
    }

    long long end = m * k;

    long long start = vis[cur.first][cur.second];

    end -= start;

    end %= total - start;

    cout << dist[end + start] << '\n';
}
