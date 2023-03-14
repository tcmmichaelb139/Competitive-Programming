#include "bits/stdc++.h"
using namespace std;

long double dist(pair<long long, long double> a, pair<long long, long double> b) {
    return (a.first - b.first) * (a.first - b.first) / (long double)(4 * b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(3);

    int n;
    cin >> n;
    vector<pair<long long, long double>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    vector<long double> ans(n, 1e9);
    stack<pair<long long, long double>> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            s.push(v[i]);
            ans[i] = v[i].second;
        } else {
            ans[i] = min((long double)v[i].second, dist(v[i], s.top()));
            while (s.size() > 1 && s.top().second < ans[i]) {
                s.pop();
                ans[i] = min(ans[i], dist(v[i], s.top()));
            }
            s.push({v[i].first, ans[i]});
        }
    }
    for (auto i : ans)
        cout << i << '\n';
}
