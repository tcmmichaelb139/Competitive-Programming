#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long mx = 0, total = 0;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        total += v[i];
    }
    cout << max(2 * mx, total) << '\n';
}
