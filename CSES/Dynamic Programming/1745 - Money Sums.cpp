#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    bool dp[n*1000+1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n*1000; j >= 0; j--) {
            if (v[i]+j > n*1000) continue;
            if (dp[j]) {
                if (!dp[v[i]+j]) total++;
                dp[v[i]+j] = true;
            }
        }
    }
    cout << total << '\n';
    for (int i = 1; i <= n*1000; i++) 
        if (dp[i]) cout << i << ' ';
    
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

