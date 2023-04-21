#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    long long operator()(pair<long long, long long> p) const { return p.first * 10007 + p.second; };
};

template <class K, class V>
using ht = gp_hash_table<K, V, chash>;

pair<long long, long long> v[40];
int num[21][(1 << 20) + 1];
ht<pair<long long, long long>, int> m;

pair<long long, long long> sumVal(int i, int add) {
    pair<long long, long long> sum;
    for (int j = 0; j < 21; j++)
        if (i & (1 << j))
            sum.first += v[j + add].first, sum.second += v[j + add].second;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int val = 0;
    for (int i = 0; i < 1 << n / 2; i++) {
        pair<long long, long long> sum = sumVal(i, 0);
        if (m.find(sum) == m.end()) {
            num[__builtin_popcount(i)][val] = 1;
            m[sum] = val++;
        } else
            num[__builtin_popcount(i)][m[sum]]++;
    }

    vector<long long> ans(n + 1, 0);
    for (int i = 0; i < 1 << (n + 1) / 2; i++) {
        pair<long long, long long> sum = sumVal(i, n / 2);
        sum = {x - sum.first, y - sum.second};
        if (m.find(sum) == m.end()) continue;
        val = m[sum];
        int pc = __builtin_popcount(i);
        for (int j = 0; j <= n / 2; j++)
            ans[j + pc] += num[j][val];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
