#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);

    int H, G;
    cin >> H >> G;
    pair<int, int> h[H+1], g[G+1];
    for (int i = 1; i <= H; i++) 
        cin >> h[i].first >> h[i].second;
    for (int i = 1; i <= G; i++) 
        cin >> g[i].first >> g[i].second;
    int dp[H+1][G+1][2]; 
    for (int i = 0; i <= H; i++) 
        for (int j = 0; j <= G; j++) 
            for (int a = 0; a < 2; a++) 
                dp[i][j][a] = 2e9;
    dp[1][0][0] = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 0; j <= G; j++) {
            if (i < H) {
                dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]+dist(h[i+1], h[i]));
                if (j != 0)
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1]+dist(h[i+1], g[j]));
            }
            if (j < G) {
                dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][0]+dist(g[j+1], h[i]));
                if (j != 0)
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1]+dist(g[j+1], g[j]));
            }
        }
    }
    cout << dp[H][G][0] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

