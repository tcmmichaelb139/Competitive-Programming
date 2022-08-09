#include "bits/stdc++.h"
using namespace std;

long long nCr[31][31];

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int s, t;
    cin >> s >> t;

    long long dp[s + 1][t + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int a = 0; a < n; a++)
        for (int i = s - 1; i >= 0; i--)
            for (int j = 0; j < t; j++)
                if (j + v[a] <= t)
                    dp[i + 1][j + v[a]] += dp[i][j];

    cout << dp[s][t] << " : " << nCr[n][s] - dp[s][t] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 31; i++) {
        nCr[i][0] = nCr[i][i] = 1;
        for (int j = 1; j < i; j++)
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Game " << i << " -- ";
        solve();
    }
}
