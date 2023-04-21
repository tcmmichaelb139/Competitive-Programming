#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, t;
    cin >> n >> t;
    deque<long long> dp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        auto it = lower_bound(begin(dp), end(dp), a + b * t) - begin(dp);
        if (dp.size() == 0 || it == 0)
            dp.push_front(a + b * t);
        else
            dp[--it] = a + b * t;
    }
    cout << dp.size() << '\n';
}
