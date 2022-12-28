#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            cur++;
        else
            cur--;
        if (cur < 0)
            s[i] = '(', cur += 2, ans++;
    }
    cout << ans + cur / 2 << '\n';
}
