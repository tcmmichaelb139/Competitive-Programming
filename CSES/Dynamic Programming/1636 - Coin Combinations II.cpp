#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
 
    long long n, x;
    cin >> n >> x;
    long long v[n];
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    long long dp[x+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= x; i++) {
            if (i+v[j] <= x) {
                dp[i+v[j]] += dp[i];
                dp[i+v[j]] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}
 
/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
 
