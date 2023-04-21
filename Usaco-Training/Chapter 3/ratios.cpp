/*
ID: tcmmich1
TASK: ratios
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> des(3);
    cin >> des[0] >> des[1] >> des[2];
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];

    int a1 = 1e8, a2 = 1e8, a3 = 1e8, num = -1;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            for (int k = 0; k <= 100; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                int ok = true;
                vector<int> sum(3, 0);
                for (int x = 0; x < 3; x++) {
                    sum[x] += i * v[0][x];
                    sum[x] += j * v[1][x];
                    sum[x] += k * v[2][x];
                    if (des[x] == 0) continue;
                    if (sum[x] % des[x] != 0)
                        ok = false;
                }
                if (ok) {
                    int mn1 = (des[0] == 0 ? -1 : sum[0] / des[0]);
                    int mn2 = (des[1] == 0 ? -2 : sum[1] / des[1]);
                    int mn3 = (des[2] == 0 ? -3 : sum[2] / des[2]);
                    if (a1 + a2 + a3 > i + j + k &&
                        ((des[0] == 0 && sum[0] == 0) || (des[1] == 0 && sum[1] == 0) || mn1 == mn2) &&
                        ((des[0] == 0 && sum[0] == 0) || (des[2] == 0 && sum[2] == 0) || mn1 == mn3) &&
                        ((des[1] == 0 && sum[1] == 0) || (des[2] == 0 && sum[2] == 0) || mn2 == mn3))
                        a1 = i, a2 = j, a3 = k, num = (des[0] == 0 ? (des[1] == 0 ? mn3 : mn2) : mn1);
                }
            }
    if (a1 == 1e8)
        cout << "NONE\n";
    else
        cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << num << '\n';
}
