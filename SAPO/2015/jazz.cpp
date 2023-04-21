#include "bits/stdc++.h"
using namespace std;

int dp[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int j = 0; j <= s.length(); j++) {
        for (int i = 0; i < s.length() - j; i++) {
            dp[i][i + j] = dp[i + 1][i + j] + 1;
            for (int k = i + 1; k <= i + j; k++)
                if (s[i] == s[k])
                    dp[i][i + j] = min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
        }
    }
    cout << dp[0][s.length() - 1] << '\n';
}
