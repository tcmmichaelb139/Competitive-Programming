#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, w;
    cin >> l >> w;

    pair<int, int> dp[l + 1][w + 1];
    for (int i = 0; i <= l; i++)
        for (int j = 0; j <= w; j++)
            dp[i][j] = {-1, -1};

    dp[0][0] = {0, 0};

    for (int i = 0; i < l; i++)
        for (int j = 0; j < w; j++)
            if (dp[i][j].first != -1)
                for (int a = 1; a <= 26; a++)
                    if (j + a <= w)
                        dp[i + 1][j + a] = {i, j};

    if (dp[l][w].first == -1) {
        cout << "impossible\n";
    } else {
        for (pair<int, int> i = {l, w}; i.first != 0; i = dp[i.first][i.second])
            cout << (char)('a' + (i.second - dp[i.first][i.second].second - 1));
        cout << '\n';
    }
}
