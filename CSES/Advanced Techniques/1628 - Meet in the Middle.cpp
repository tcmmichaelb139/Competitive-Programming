#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v), end(v));
    vector<long long> v1, v2;
    for (int i = 0; i < n; i++) {
        if (i < n / 2)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    vector<long long> s1, s2;
    for (int i = 0; i < (1 << v1.size()); i++) {
        long long sum = 0;
        for (int j = 0; j < 31; j++)
            if (i & (1 << j)) sum += v1[j];
        s1.push_back(sum);
    }
    for (int i = 0; i < (1 << v2.size()); i++) {
        long long sum = 0;
        for (int j = 0; j < 31; j++)
            if (i & (1 << j)) sum += v2[j];
        s2.push_back(sum);
    }
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    long long ans = 0;
    int r = s2.size() - 1;
    for (int l = 0; l < s1.size(); l++) {
        auto lower = lower_bound(begin(s2), end(s2), x - s1[l]);
        auto upper = upper_bound(begin(s2), end(s2), x - s1[l]);
        ans += (upper - begin(s2)) - (lower - begin(s2));
    }
    cout << ans << '\n';
}
