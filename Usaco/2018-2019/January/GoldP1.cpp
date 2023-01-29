#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;

long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i].first >> words[i].second;
    map<char, long long> rhyme;
    for (int i = 0; i < m; i++) {
        char a;
        cin >> a;
        rhyme[a]++;
    }

    vector<int> num_rhyme(n + 1);
    long long dpwo[k + 1];
    memset(dpwo, 0, sizeof dpwo);

    dpwo[0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (i + words[j].first > k) continue;
            dpwo[i + words[j].first] = add(dpwo[i + words[j].first], dpwo[i]);
            if (i + words[j].first == k)
                num_rhyme[words[j].second] = add(num_rhyme[words[j].second], dpwo[i]);
        }
    }

    long long ans = 1;
    for (auto i : rhyme) {
        long long total = 0;
        for (auto j : num_rhyme)
            total = add(total, binpow(j, i.second));
        ans = mult(ans, total);
    }

    cout << ans << '\n';
}
