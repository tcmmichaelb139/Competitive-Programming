#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    auto left = [&](int x, int y) {
        int sum = 0;
        for (int i = 0; i <= k; i++) {
            if (y - i < 0) break;
            if (x - k + i >= 0)
                sum += v[x - k + i][y - i];
            if (x + k - i < n && i != k)
                sum += v[x + k - i][y - i];
        }
        return sum;
    };

    auto right = [&](int x, int y) {
        int sum = 0;
        for (int i = 0; i <= k; i++) {
            if (y + i >= n) break;
            if (x - k + i >= 0)
                sum += v[x - k + i][y + i];
            if (x + k - i < n && i != k)
                sum += v[x + k - i][y + i];
        }
        return sum;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= k; j++)
            for (int a = i - k + j; a <= i + k - j; a++)
                if (j >= 0 && j < n && a >= 0 && a < n)
                    sum += v[a][j];

        for (int j = 0; j < n; j++) {
            ans = max(ans, sum);
            sum -= left(i, j);
            sum += right(i, j + 1);
        }
    }
    cout << ans << '\n';
}
