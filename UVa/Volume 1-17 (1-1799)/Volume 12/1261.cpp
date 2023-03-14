#include "bits/stdc++.h"
using namespace std;

void solve() {
    string s;
    cin >> s;
    set<pair<int, string>, greater<pair<int, string>>> pos;
    pos.insert({s.length(), s});
    while (pos.size()) {
        pair<int, string> cur = *pos.begin();
        pos.erase(pos.begin());
        string k = cur.second;
        int n = cur.first;

        if (n == 0) {
            cout << 1 << '\n';
            return;
        }

        for (int i = 0; i < n;) {
            int same = 1;
            for (int j = i + 1; j < n; j++) {
                if (k[i] != k[j]) break;
                same++;
                pos.insert({n - same, k.substr(0, i) + k.substr(i + same, n - (i + same))});
            }
            i += same;
        }
    }
    cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
