#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);

    int t, a, b;
    cin >> t >> a >> b;

    bool dp[t+1][2]; memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 0; i <= t; i++) {
        if (dp[i][0]) {
            if (i+a <= t) dp[i+a][0] = true;
            if (i+b <= t) dp[i+b][0] = true;
            if (!dp[(int)floor(i/2)][1]) {
                dp[(int)floor(i/2)][1] = true;
                i = floor(i/2);
            }
        }
        if (dp[i][1]) {
            if (i+a <= t) dp[i+a][1] = true;
            if (i+b <= t) dp[i+b][1] = true;
        }
    }
    for (int i = t; i >= 0; i--) {
        if (dp[i][0] || dp[i][1]) {
            cout << i << '\n';
            return 0;
        }
    }
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
