#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> neg, pos;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a < 0)
            neg.push_back(a);
        else
            pos.push_back(a);
    }

    pos.push_back(0);
    neg.push_back(0);

    sort(begin(pos), end(pos));
    sort(rbegin(neg), rend(neg));

    long long dp[size(pos)][size(neg)][2];

    for (int i = 0; i < size(pos); i++)
        for (int j = 0; j < size(neg); j++)
            dp[i][j][0] = dp[i][j][1] = 1e18;

    dp[0][0][0] = dp[0][0][1] = 0;

    for (int i = 0; i < size(pos); i++) {
        for (int j = 0; j < size(neg); j++) {
            if (i + 1 < size(pos)) {
                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + (pos[i + 1] - pos[i]) * (n - i - j));
                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + (pos[i + 1] - neg[j]) * (n - i - j));
            }

            if (j + 1 < size(neg)) {
                dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + (pos[i] - neg[j + 1]) * (n - i - j));
                dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + (neg[j] - neg[j + 1]) * (n - i - j));
            }
        }
    }

    cout << min(dp[size(pos) - 1][size(neg) - 1][0], dp[size(pos) - 1][size(neg) - 1][1]) << '\n';
}
