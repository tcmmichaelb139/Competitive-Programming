/*
ID: tcmmich1
TASK: heritage
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

string in, pre;
int i;
int pos[26];

string solve(int l, int r) {
    if (l > r)
        return "";

    char root = pre[i++];
    int p = pos[root - 'A'];
    string left = solve(l, p - 1);
    string right = solve(p + 1, r);
    return left + right + root;
}

int main() {
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> in >> pre;
    for (int j = 0; j < in.length(); j++)
        pos[in[j] - 'A'] = j;

    cout << solve(0, in.length() - 1) << '\n';
}
