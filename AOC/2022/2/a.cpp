#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    char s1, s2;
    int ans = 0;
    while (cin >> s1 >> s2) {
        int x1 = s1 - 'A';
        int x2 = s2 - 'X' + 1;
        if (x2 == 1) {
            x1 += 2;
            x1 %= 3;
        } else if (x2 == 2) {
            ans += 3;
        } else if (x2 == 3) {
            ans += 6;
            x1 += 1;
            x1 %= 3;
        }
        ans += x1 + 1;
    }
    cout << ans << '\n';
}
