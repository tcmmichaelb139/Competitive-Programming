#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    auto add = [&](long long a, long long b) { return (a + b) % m; };
    auto mult = [&](long long a, long long b) { return a * b % m; };

    vector<long long> ans(n + 1);
    ans[0] = 1;
    if (n >= 2) ans[1] = 0;
    for (long long i = 2; i <= n; i++)
        ans[i] = mult(i - 1, add(ans[i - 1], ans[i - 2]));
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
