#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n;
    cin >> n;
    bool v[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '*') v[i][j] = false;
            else v[i][j] = true;
        }
    }
    if (n == 1) {
        cout << v[0][0] ? 1 : 0 << '\n';
        return 0;
    }
    long long dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            if (!v[i][j]) continue;
            if (i+1 < n && v[i+1][j]) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            if (j+1 < n && v[i][j+1]) {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

