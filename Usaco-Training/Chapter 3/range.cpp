/*
ID: tcmmich1
TASK: range
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')
                pref[i][j + 1] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] += pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];

    vector<int> ans(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 2; k <= n - max(i, j); k++) {
                if (k * k == pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j]) {
                    ans[k]++;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (ans[i] == 0) break;
        cout << i << ' ' << ans[i] << '\n';
    }
}
