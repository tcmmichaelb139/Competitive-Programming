#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long ans = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (cur < a)
            ans += a - cur;
        cur = a;
    }
    cout << ans << '\n';
}
