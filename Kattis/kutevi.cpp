#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<bool> dp(360, false);
    dp[0] = true;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < 360; i++)
            if (dp[i])
                for (int j = 0; j < n; j++)
                    if (!dp[(i + v[j]) % 360])
                        dp[(i + v[j]) % 360] = true, changed = true;
    }

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;

        cout << (dp[a] ? "YES" : "NO") << '\n';
    }
}
