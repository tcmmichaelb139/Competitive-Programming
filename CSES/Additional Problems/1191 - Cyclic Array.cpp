#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200001, MS = 19;

int n;
long long k;
int jmp[MS][MAXN];
long long sum[MS][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<long long> v(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    if (total <= k) {
        cout << 1 << '\n';
        return 0;
    }

    int r = 0;
    long long sum_cur = 0;
    for (int l = 0; l < n; l++) {
        int num = 0;
        while (sum_cur + v[r % n] <= k) {
            sum_cur += v[r++ % n];
        }

        jmp[0][l] = r % n;
        sum[0][l] = r - l;

        sum_cur -= v[l];
    }

    for (int i = 1; i < MS; i++) {
        for (int j = 0; j < n; j++) {
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][jmp[i - 1][j]];
        }
    }

    auto check = [&](int dist) {
        for (int i = 0; i < n; i++) {
            long long len = 0;
            int cur = i;
            for (int j = MS - 1; j >= 0; j--)
                if (dist & (1 << j)) {
                    len += sum[j][cur];
                    cur = jmp[j][cur];
                }
            if (len >= n) return true;
        }
        return false;
    };

    int l = 1;
    r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << '\n';
}
