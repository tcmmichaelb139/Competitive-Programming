#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n;
    cin >> w >> n;
    vector<string> words(w);
    map<string, int> m;
    for (int i = 0; i < w; i++)
        cin >> words[i], m[words[i]] = i + 1;
    sort(begin(words), end(words));
    for (int i = 0; i < n; i++) {
        int k;
        string s;
        cin >> k >> s;
        int ind = lower_bound(begin(words), end(words), s) - begin(words) + k - 1;
        bool ok = true;
        if (ind < w) {
            for (int j = 0; j < s.length(); j++)
                if (s[j] != words[ind][j])
                    ok = false;
        } else
            ok = false;

        cout << (ok ? m[words[ind]] : -1) << '\n';
    }
}
