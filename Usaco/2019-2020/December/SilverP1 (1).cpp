#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long l = 1, r = 10000000000000000;
    int runs = 10000;
    while (l < r && runs) {
        long long mid = l + (r - l) / 2;

        if (mid % 3 == 0 || mid % 5 == 0)
            mid++;
        if (mid >= r)
            mid -= 2;

        long long num = mid - mid / 3 - mid / 5 + mid / 15;

        if (num > n)
            r = mid - 1;
        else
            l = mid;

        runs--;
    }

    for (long long i = max(1ll, l - 100); i < l + 100; i++)
        if (i - i / 3 - i / 5 + i / 15 == n && i % 3 != 0 && i % 5 != 0) {
            cout << i << '\n';
            return 0;
        }
}
