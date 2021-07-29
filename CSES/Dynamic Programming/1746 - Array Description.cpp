#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    long long dp[n][m+1]; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= m; j++) 
            dp[i][j] = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            if (i == 0) {
                for (int j = 1; j <= m; j++) 
                    dp[i][j] = 1;
            } else {
                if (v[i-1] == 0) {
                    for (int j = 1; j <= m; j++) {
                        if (j > 1) dp[i][j] += dp[i-1][j-1];
                        dp[i][j] %= MOD;
                        if (j < m) dp[i][j] += dp[i-1][j+1];
                        dp[i][j] %= MOD;
                        dp[i][j] += dp[i-1][j];
                        dp[i][j] %= MOD;
                    }
                } else {
                    /* cout << i << ' ' << v[i] << '\n'; */
                    if (v[i-1] > 1) dp[i][v[i-1]-1] += dp[i-1][v[i-1]];
                    dp[i][v[i-1]-1] %= MOD;
                    if (v[i-1] < m) dp[i][v[i-1]+1] += dp[i-1][v[i-1]];
                    dp[i][v[i-1]+1] %= MOD;
                    dp[i][v[i-1]] += dp[i-1][v[i-1]];
                    dp[i][v[i-1]] %= MOD;
                }
            }
        } else {
            if (i == 0) {
                dp[i][v[i]] = 1;
            } else {
                if (v[i] > 1) dp[i][v[i]] += dp[i-1][v[i]-1];
                dp[i][v[i]] %= MOD;
                if (v[i] < m) dp[i][v[i]] += dp[i-1][v[i]+1];
                dp[i][v[i]] %= MOD;
                dp[i][v[i]] += dp[i-1][v[i]];
                dp[i][v[i]] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n-1][i]; 
        ans %= MOD;
    }
    cout << ans << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

