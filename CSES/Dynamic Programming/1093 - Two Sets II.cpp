#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    long long halfSum = (n*(n+1))/2;
    if (halfSum&1) {
        cout << 0 << '\n';
        return 0;
    }
    halfSum /= 2;
    long long dp[n+1][halfSum+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= halfSum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-i >= 0) 
                dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][halfSum] << '\n';
}
