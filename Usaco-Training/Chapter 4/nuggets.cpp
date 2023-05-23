/*
ID: tcmmich1
TASK: nuggets
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

const int MAX = 100000;

int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> num(2, 0);
    for (int i = 0; i < n; i++)
        num[v[i] & 1]++;

    if (num[0] == 0 || num[1] == 0) {
        cout << 0 << '\n';
        return 0;
    }

    bool dp[MAX];
    memset(dp, false, sizeof dp);
    dp[0] = true;
    for (int i = 0; i < MAX; i++) {
        if (!dp[i]) continue;
        for (int j = 0; j < n; j++) {
            if (i + v[j] < MAX)
                dp[i + v[j]] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < MAX; i++) {
        if (!dp[i])
            ans = max(ans, i);
    }

    cout << ans << '\n';
}
