#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(begin(v), end(v));

    set<int> s;
    s.insert(v[0].second);
    for (int i = 1; i < n; i++) {
        auto it = s.lower_bound(v[i].second);

        if (it == s.begin())
            s.insert(v[i].second);
        else {
            s.erase(--it);
            s.insert(v[i].second);
        }
    }

    cout << s.size() << '\n';
}
