#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;
    map<int, vector<int>> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a].push_back(i);
    }

    vector<pair<int, int>> sol;

    multiset<int> diff, cur;

    for (auto i : v) {
        if (i.first == 0) {
            for (int j = 0; j < i.second.size(); j++) {
                if (j > 0)
                    diff.insert(i.second[j] - i.second[j - 1]);
                cur.insert(i.second[j]);
            }
        } else {
            for (auto j : i.second) {
                auto it = cur.lower_bound(j);
                int g = *it;
                int l = *(--it);

                diff.erase(diff.find(g - l));
                diff.insert(g - j);
                diff.insert(j - l);
                cur.insert(j);
            }
        }
        sol.push_back({i.first, *(--diff.end())});
    }

    for (int i = 0; i < b; i++) {
        int s, d;
        cin >> s >> d;

        pair<int, int> best = *(--lower_bound(begin(sol), end(sol), make_pair(s + 1, -1)));

        cout << (best.second <= d) << '\n';
    }
}
