#include "bits/stdc++.h"
using namespace std;

const double EPS = 0.0001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> s[i];
    double m;
    cin >> m;
    cout << setprecision(12) << fixed << '\n';

    auto dist = [](pair<int, int> a, pair<int, int> b) {
        return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    };

    auto check = [&](double v) {
        double dp[1 << n][n];
        for (int i = 0; i < 1 << n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = 1e18;
        double vel[n];
        vel[0] = v;
        for (int i = 1; i < n; i++)
            vel[i] = vel[i - 1] * m;
        for (int i = 0; i < n; i++)
            if (dist({0, 0}, {x[i], y[i]}) <= s[i] * v)
                dp[1 << i][i] = dist({0, 0}, {x[i], y[i]}) / v;
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) continue;

                for (int a = 0; a < n; a++) {
                    if (i & (1 << a)) continue;

                    double d = dist({x[j], y[j]}, {x[a], y[a]});
                    double ve = vel[__builtin_popcount(i)];

                    if (d <= (s[a] - dp[i][j]) * ve)
                        dp[i | (1 << a)][a] = min(dp[i | (1 << a)][a], dp[i][j] + d / ve);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (dp[(1 << n) - 1][i] < 1e18)
                return true;
        return false;
    };

    double l = 0, r = 1e9;
    while ((r - l) > EPS) {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << l << '\n';
}
