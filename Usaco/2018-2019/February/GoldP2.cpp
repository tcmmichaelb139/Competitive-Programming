#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    deque<vector<int>> s;
    int mx = -1;
    int i = 0;
    for (; i < n; i++) {
        if (mx > v[i]) break;
        if (s.size() == 0 || s[s.size() - 1][0] < v[i]) {
            s.push_back({v[i]});
        } else {
            int l = 0, r = s.size();
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (s[mid][0] > v[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (s[l][s[l].size() - 1] < v[i]) {
                while (l > 0) {
                    while (s[0].size()) {
                        mx = max(mx, s[l][s[l].size() - 1]);
                        s[0].pop_back();
                    }
                    s.pop_front();
                    l--;
                }
                while (s[l].size() && s[l][s[l].size() - 1] < v[i]) {
                    mx = max(mx, s[l][s[l].size() - 1]);
                    s[l].pop_back();
                }
            }
            s[l].push_back(v[i]);
        }
    }
    cout << i << '\n';
}
