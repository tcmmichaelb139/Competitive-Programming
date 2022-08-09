#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    bool add = false;
    while (s.size()) {
        vector<int> cur;
        for (auto i : s) {
            if (add) {
                cur.push_back(i);
            }
            add = !add;
        }
        for (int i = 0; i < cur.size(); i++) {
            cout << cur[i] << ' ';
            s.erase(cur[i]);
        }
    }
    cout << '\n';
}
