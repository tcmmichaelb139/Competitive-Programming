/*
ID: tcmmich1
TASK: kimbits
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

long long v[33][33];

void solve(long long n, long long bits, long long i) {
    if (n == 0) return;
    if (v[n - 1][bits] <= i) {
        cout << 1;
        solve(n - 1, bits - 1, i - v[n - 1][bits]);
    } else {
        cout << 0;
        solve(n - 1, bits, i);
    }
}

int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, L, I;
    cin >> N >> L >> I;
    for (int i = 0; i <= 32; i++)
        v[0][i] = 1;
    for (int i = 1; i <= 32; i++) {
        for (int j = 0; j <= 32; j++) {
            if (j == 0)
                v[i][j] = 1;
            else
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    solve(N, L, I - 1);
    cout << '\n';
}
