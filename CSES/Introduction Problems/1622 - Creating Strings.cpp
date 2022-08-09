#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    set<string> ans;
    sort(begin(s), end(s));
    do {
        ans.insert(s);
    } while (next_permutation(begin(s), end(s)));
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << '\n';
}
