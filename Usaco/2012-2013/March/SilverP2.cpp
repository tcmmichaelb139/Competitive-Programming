#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int v[n][4];
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> v[i][j];

        edges.push_back({v[i][0], {i, 1}});
        edges.push_back({v[i][2], {i, 0}});
    }

    sort(begin(edges), end(edges));

    vector<bool> vis(n, false);
    multiset<pair<int, int>> s;

    s.insert({1e9, 1});

    int ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        int ind = edges[i].second.first;

        pair<int, int> k = *(s.lower_bound({v[ind][3], -1}));

        if (edges[i].second.second) {
            if (k.second) {
                ans++;
                vis[ind] = true;

                s.insert({v[ind][1], 1});
                s.insert({v[ind][3], 0});
            }
        } else {
            if (vis[ind]) {
                s.erase({v[ind][1], 1});
                s.erase({v[ind][3], 0});
            }
        }
    }
    cout << ans << '\n';
}
