#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    vector<pair<int, int>> sx = v, sy = v;
    sort(begin(sx), end(sx));
    sort(begin(sy), end(sy), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    auto run = [&](int i, set<pair<int, int>> &done) {
        int cur = 0;
        if (i == 0) {  // left
            while (done.find(sx[cur]) != done.end())
                cur++;
            done.insert(sx[cur]);
        } else if (i == 1) {  // up
            cur = n - 1;
            while (done.find(sy[cur]) != done.end())
                cur--;
            done.insert(sy[cur]);
        } else if (i == 2) {  // right
            cur = n - 1;
            while (done.find(sx[cur]) != done.end())
                cur--;
            done.insert(sx[cur]);
        } else {  // down
            while (done.find(sy[cur]) != done.end())
                cur++;
            done.insert(sy[cur]);
        }
    };

    int ans = 2000000000;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                set<pair<int, int>> done;

                run(i, done);
                run(j, done);
                run(k, done);

                pair<int, int> x = {1000000000, 0};
                pair<int, int> y = {1000000000, 0};

                for (auto a : sx) {
                    if (done.find(a) != done.end()) continue;
                    x.first = min(x.first, a.first);
                    x.second = max(x.second, a.first);
                    y.first = min(y.first, a.second);
                    y.second = max(y.second, a.second);
                }
                ans = min(ans, (x.second - x.first) * (y.second - y.first));
            }
    cout << ans << '\n';
}
