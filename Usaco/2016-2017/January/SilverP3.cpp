#include "bits/stdc++.h"
using namespace std;

string s;
long long n;

char solve(long long a) {
    long long cur = 0, len = s.length();
    while (len <= a) len *= 2, cur++;
    if (!cur) return s[a];
    len /= 2;
    if (a == len) return solve(len - 1);
    return solve(a - len - 1);
}

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;

    cout << solve(n - 1) << '\n';
}
