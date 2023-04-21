#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;
    vector<long long> dp;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        a = m * i - a;
        if (a < 0) continue;
        int p = upper_bound(begin(dp), end(dp), a) - begin(dp);
        if (p == dp.size())
            dp.push_back(a);
        else
            dp[p] = a;
    }
    cout << n - dp.size() << '\n';
}
