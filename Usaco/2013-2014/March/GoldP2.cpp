#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int all = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        all += v[i];
    }

    auto check = [&](double a) {
        double cur = v[1] - a, best = v[1] - a;
        for (int i = 2; i < n - 1; i++) {
            if (cur < 0) cur = 0;
            cur += v[i] - a;
            best = max(best, cur);
        }
        return best >= all - a * n;
    };

    double l = 1, r = 1e9;
    while (r - l > 0.00001) {
        double mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(3) << l << '\n';
}
