#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    int x = a.first-b.first;
    int y = a.second-b.second;
    return x*x+y*y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);

    int n, m;
    cin >> n >> m;
    int fx, fy, bx, by;
    cin >> fx >> fy >> bx >> by;
    string fs, bs;
    cin >> fs >> bs;
    vector<pair<int, int>> fv, bv;
    fv.push_back({fx, fy});
    bv.push_back({bx, by});
    for (int i = 0; i < n; i++) {
        if (fs[i] == 'N')
            fy++;
        else if (fs[i] == 'E')
            fx++;
        else if (fs[i] == 'S')
            fy--;
        else 
            fx--;
        fv.push_back({fx, fy});
    }
    for (int i = 0; i < m; i++) {
        if (bs[i] == 'N')
            by++;
        else if (bs[i] == 'E')
            bx++;
        else if (bs[i] == 'S')
            by--;
        else 
            bx--;
        bv.push_back({bx, by});
    }
    int dp[n+1][m+1]; // [index][index] = min energy to get there
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) 
            dp[i][j] = 2e9;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) 
        dp[i][0] = dp[i-1][0]+dist(fv[i], bv[0]);
    for (int i = 1; i <= m; i++) 
        dp[0][i] = dp[0][i-1]+dist(fv[0], bv[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dist(fv[i], bv[j]);
            int tmp = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            dp[i][j] += tmp;
        }
    }
    cout << dp[n][m] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
