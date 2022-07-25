#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] -= k;
    }
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    cout << ans << '\n';
}
