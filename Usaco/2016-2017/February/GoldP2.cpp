#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);

    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < n; i++) 
        cin >> v2[i];
    int dp[n+1][n+1]; // index of v1 and index of v2
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(v1[i]-v2[j]) <= 4) {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
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

