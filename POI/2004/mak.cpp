#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e4 + 1, MAXP = 71;

vector<int> primes;
double dp[MAXN][2];
int pre[MAXN][MAXP];

void findPrimes() {
    bitset<MAXN> isPrime;

    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 4; i < MAXN; i += 2) isPrime[i] = 0;
    for (int i = 3; i * i < MAXN; i += 2)
        if (isPrime[i])
            for (int j = i * i; j < MAXN; j += i * 2) isPrime[j] = 0;
    for (int i = 0; i < MAXN; i++)
        if (isPrime[i]) primes.push_back(i);
}

void solve() {
    for (int j = 1; j < MAXP; j++) {
        for (int i = 2; i < MAXN; i++) {
            pre[i][j] = i;
            dp[i][1] = dp[i][0];
            int k = primes[j - 1];
            while (i >= k) {
                if (dp[i][1] < dp[i - k][0] + log(k)) {
                    dp[i][1] = dp[i - k][0] + log(k);
                    pre[i][j] = i - k;
                }
                k *= primes[j - 1];
            }
        }
        for (int i = 0; i < MAXN; i++)
            dp[i][0] = dp[i][1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    findPrimes();
    solve();
    while (t--) {
        int n;
        cin >> n;
        int nn = n;
        vector<int> v;
        int cur = 70;
        while (cur) {
            int pos = 1;
            for (int i = cur; i >= 1; i--) {
                if (pre[n][i] != n) {
                    v.push_back(n - pre[n][i]);
                    n = pre[n][i];
                    pos = i;
                    break;
                }
            }
            cur = pos - 1;
        }
        while (n--) v.push_back(1);
        sort(begin(v), end(v));
        vector<int> ans(nn);
        iota(begin(ans), end(ans), 1);
        cur = 0;
        for (int i = 0; i < v.size(); i++) {
            rotate(begin(ans) + cur, begin(ans) + 1 + cur, begin(ans) + v[i] + cur);
            cur += v[i];
        }
        for (int i = 0; i < nn; i++)
            cout << ans[i] << " \n"[i + 1 == nn];
    }
}
