#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> coord(int x, int y, string s) {
    vector<pair<int, int>> pos(s.length() + 1);

    s += '?';

    for (int i = 0; i < s.length(); i++) {
        pos[i] = {x, y};
        if (s[i] == 'N')
            y++;
        if (s[i] == 'S')
            y--;
        if (s[i] == 'E')
            x++;
        if (s[i] == 'W')
            x--;
    }

    return pos;
}

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto dist = [](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
    };

    int n, m;
    cin >> n >> m;
    int fx, fy, bx, by;
    cin >> fx >> fy >> bx >> by;
    string fs, bs;
    cin >> fs >> bs;

    vector<pair<int, int>> posf(n + 1), posb(m + 1);
    posf = coord(fx, fy, fs);
    posb = coord(bx, by, bs);

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e9;

    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(posf[i + 1], posb[j]));
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(posf[i], posb[j + 1]));
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(posf[i + 1], posb[j + 1]));
        }

    cout << dp[n][m] << '\n';
}
