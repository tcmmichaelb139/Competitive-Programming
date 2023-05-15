#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        vector<int> mx(2, 0);
        for (int j = 0; j < n; j++) {
            mx[j & 1] += v[i][j];
        }
        row += max(mx[0], mx[1]);
    }

    for (int i = 0; i < n; i++) {
        vector<int> mx(2, 0);
        for (int j = 0; j < n; j++) {
            mx[j & 1] += v[j][i];
        }
        col += max(mx[0], mx[1]);
    }

    cout << max(row, col) << '\n';
}
