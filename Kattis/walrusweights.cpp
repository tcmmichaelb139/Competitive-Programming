#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    bool dp[2001];
    memset(dp, false, sizeof dp);

    dp[0] = true;

    for (int i = 0; i < n; i++)
        for (int j = 1000; j >= 0; j--)
            if (dp[j])
                dp[j + v[i]] = true;

    for (int i = 0; i <= 1000; i++) {
        if (dp[1000 + i]) {
            cout << 1000 + i << '\n';
            break;
        } else if (dp[1000 - i]) {
            cout << 1000 - i << '\n';
            break;
        }
    }
}
