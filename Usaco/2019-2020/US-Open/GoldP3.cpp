#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, MOD;
    cin >> n >> MOD;

    auto add = [&](long long a, long long b) { return (a + b) % MOD; };
    auto mult = [&](long long a, long long b) { return a * b % MOD; };

    vector<long long> primes;
    primes.push_back(2);
    vector<bool> prime(n, true);
    for (int i = 4; i <= n; i += 2)
        prime[i] = false;
    for (int i = 3; i <= n; i++)
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }

    if (primes.size() == 0) {
        cout << 1 << '\n';
        return 0;
    }

    long long dp[primes.size() + 1][n + 1];

    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) dp[0][i] = 1;

    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
            long long len = primes[i];
            while (j + len <= n) {
                dp[i + 1][j + len] = add(dp[i + 1][j + len], mult(dp[i][j], len));
                len *= primes[i];
            }
        }
    }

    cout << dp[primes.size()][n] << '\n';
}
