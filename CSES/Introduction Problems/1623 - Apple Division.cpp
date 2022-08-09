#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long ans = 1e18;

    for (int i = 1; i <= (1 << n) - 1; i++) {
        long long sum1 = 0, sum2 = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (i & (1 << j))
                sum1 += v[j];
            else
                sum2 += v[j];
        }
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans << '\n';
}
