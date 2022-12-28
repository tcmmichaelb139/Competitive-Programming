#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto dist = [](pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    };

    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    int ans = 0;
    vector<bool> vis(n, false);
    vector<int> mndist(n, 1e9);
    mndist[0] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && (k == -1 || mndist[k] > mndist[j]))
                k = j;

        if (k == -1) break;

        if (mndist[k] == 1e9) {
            ans = -1;
            break;
        }

        vis[k] = true;
        ans += mndist[k];

        for (int j = 0; j < n; j++) {
            if (dist(v[k], v[j]) < c) continue;
            mndist[j] = min(mndist[j], dist(v[k], v[j]));
        }
    }
    cout << ans << '\n';
}
