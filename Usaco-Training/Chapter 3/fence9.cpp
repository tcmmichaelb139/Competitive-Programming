/*
ID: tcmmich1
TASK: fence9
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

const double EPS = 1e-9;

int main() {
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    double n, m, p;
    cin >> n >> m >> p;

    auto calc1 = [&](double y) {
        return ceil(y * n / m + EPS);
    };

    auto calc2 = [&](double y) {
        return floor(y * (n - p) / m + p - EPS);
    };

    int ans = 0;

    for (int i = 1; i < m; i++) {
        ans += (int)(calc2(i) - calc1(i)) + 1;
    }

    cout << ans << '\n';
}
