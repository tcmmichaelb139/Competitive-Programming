#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 1;

int v[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 1; j * j <= a; j++) {
            if (a % j == 0)
                v[j]++, v[a / j]++;
            if (j == a / j) v[j]--;
        }
    }
    for (int i = MAXN - 1; i >= 1; i--) {
        if (v[i] > 1) {
            cout << i << '\n';
            break;
        }
    }
}
