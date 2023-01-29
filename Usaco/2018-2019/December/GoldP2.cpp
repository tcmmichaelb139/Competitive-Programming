#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            cin >> v[i][j];
        sort(begin(v[i]), end(v[i]));
    }

    long long ans = (n * (n - 1)) / 2;
    map<int, long long> one;
    map<pair<int, int>, long long> two;
    map<pair<int, pair<int, int>>, long long> three;
    map<pair<pair<int, int>, pair<int, int>>, long long> four;
    map<pair<pair<int, int>, pair<int, pair<int, int>>>, long long> five;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int a = 0; a < 5; a++) {
            sum += one[v[i][a]];
            for (int b = a + 1; b < 5; b++) {
                sum -= two[{v[i][a], v[i][b]}];
                for (int c = b + 1; c < 5; c++) {
                    sum += three[{v[i][a], {v[i][b], v[i][c]}}];
                    for (int d = c + 1; d < 5; d++) {
                        sum -= four[{{v[i][a], v[i][b]}, {v[i][c], v[i][d]}}];
                        for (int e = d + 1; e < 5; e++)
                            sum += five[{{v[i][a], v[i][b]}, {v[i][c], {v[i][d], v[i][e]}}}];
                    }
                }
            }
        }

        ans -= sum;

        for (int a = 0; a < 5; a++) {
            one[v[i][a]]++;
            for (int b = a + 1; b < 5; b++) {
                two[{v[i][a], v[i][b]}]++;
                for (int c = b + 1; c < 5; c++) {
                    three[{v[i][a], {v[i][b], v[i][c]}}]++;
                    for (int d = c + 1; d < 5; d++) {
                        four[{{v[i][a], v[i][b]}, {v[i][c], v[i][d]}}]++;
                        for (int e = d + 1; e < 5; e++)
                            five[{{v[i][a], v[i][b]}, {v[i][c], {v[i][d], v[i][e]}}}]++;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
// troll
