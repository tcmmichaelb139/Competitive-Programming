/*
ID: tcmmich1
TASK: spin
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 5;
    vector<long long> s(n);
    vector<vector<pair<long long, long long>>> v(5);
    for (int i = 0; i < n; i++) {
        long long a, w;
        cin >> a >> w;

        s[i] = a;
        for (int j = 0; j < w; j++) {
            long long b, c;
            cin >> b >> c;
            v[i].push_back({b, c});
        }
    }

    for (int i = 0; i < 30000; i++) {
        vector<vector<bool>> ok(5, vector<bool>(360, false));
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < v[a].size(); b++) {
                int start = (i * s[a] + v[a][b].first) % 360;

                for (int j = start; j <= start + v[a][b].second; j++)
                    ok[a][j % 360] = true;
            }
        }
        for (int j = 0; j < 360; j++) {
            if (ok[0][j] && ok[1][j] && ok[2][j] && ok[3][j] && ok[4][j]) {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << "none\n";
}
