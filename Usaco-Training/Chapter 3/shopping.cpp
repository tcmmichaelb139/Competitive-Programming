/*
ID: tcmmich1
TASK: shopping
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

vector<pair<vector<pair<int, int>>, int>> of;

int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int j = 0; j < n; j++) {
            int c, k;
            cin >> c >> k;
            v.push_back({c, k});
        }
        int p;
        cin >> p;
        of.push_back({v, p});
    }

    vector<pair<pair<int, int>, int>> prod;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c, k, p;
        cin >> c >> k >> p;
        prod.push_back({{c, k}, p});
    }

    for (int i = s - 1; i >= 0; i--) {
        bool ok = true;
        for (auto j : of[i].first) {
            bool okk = false;
            for (auto k : prod)
                if (j.first == k.first.first)
                    okk = true;
            if (!okk) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            of.erase(begin(of) + i);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < size(of); j++)
            for (int k = 0; k < size(of[j].first); k++)
                if (of[j].first[k].first == prod[i].first.first)
                    of[j].first[k].first = i;
        prod[i].first.first = i;
    }

    map<vector<int>, int> dp;
    vector<int> des(5, 0);
    for (int i = 0; i < m; i++)
        des[i] = prod[i].first.second;
    dp[vector<int>(5, 0)] = 0;
    for (int a = 0; a <= 5; a++) {
        for (int b = 0; b <= 5; b++) {
            for (int c = 0; c <= 5; c++) {
                for (int d = 0; d <= 5; d++) {
                    for (int e = 0; e <= 5; e++) {
                        vector<int> v = {a, b, c, d, e};
                        if (dp.find(v) == end(dp)) continue;
                        int dpval = dp[v];
                        vector<int> u = v;
                        for (int i = 0; i < m; i++) {
                            u[i]++;
                            if (dp.find(u) == end(dp))
                                dp[u] = dpval + prod[i].second;
                            else
                                dp[u] = min(dp[u], dpval + prod[i].second);
                            u[i]--;
                        }
                        for (int i = 0; i < size(of); i++) {
                            for (auto j : of[i].first)
                                u[j.first] += j.second;
                            if (dp.find(u) == end(dp))
                                dp[u] = dpval + of[i].second;
                            else
                                dp[u] = min(dp[u], dpval + of[i].second);
                            for (auto j : of[i].first)
                                u[j.first] -= j.second;
                        }
                    }
                }
            }
        }
    }
    cout << dp[des] << '\n';
}
