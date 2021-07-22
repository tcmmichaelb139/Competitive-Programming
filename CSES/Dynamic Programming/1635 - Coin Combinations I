#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, x;
    cin >> n >> x;
    pair<int, int> v[n];
    for (int i = 0; i < n; i++) 
        cin >> v[i].first;
    for (int i = 0; i < n; i++) 
        cin >> v[i].second;
    int dp[x+1];
    memset(dp, -100, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j+v[i].first > x) continue;
            dp[j+v[i].first] = max(dp[j+v[i].first], dp[j]+v[i].second);
        }
    }
    int ans = 0;
    for (int i = 0; i <= x; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

