#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> v(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];

    vector<vector<long long>> prev(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        prev[i][i] = 1;

    for (int i = 1; i < n; i++) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int a = 1; a <= n; a++) {
            int b = n - a - i + 1;
            if (b < 1) continue;
            for (int c = 1; c <= n; c++) {
                int d = n - c + i + 1;
                if (d > n) continue;

                if (v[a][b] != v[c][d]) continue;

                dp[a][c] = prev[a][c];

                if (a + 1 <= n && c - 1 >= 1) {
                    dp[a][c] = add(dp[a][c], prev[a + 1][c - 1]);
                }
                if (a + 1 <= n) {
                    dp[a][c] = add(dp[a][c], prev[a + 1][c]);
                }
                if (c - 1 >= 1) {
                    dp[a][c] = add(dp[a][c], prev[a][c - 1]);
                }
            }
        }
        swap(prev, dp);
    }

    cout << prev[1][n] << '\n';
}
