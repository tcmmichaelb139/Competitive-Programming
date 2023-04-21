#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200001;
const int MAXB = 32;

int jmp[MAXB][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        jmp[0][i] = a;
    }

    for (int i = 1; i < MAXB; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < MAXB; j++)
            if (b & (1 << j))
                a = jmp[j][a];
        cout << a << '\n';
    }
}
