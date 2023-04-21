#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> jmp(20, vector<int>(n + 1));
    for (int i = 2; i <= n; i++) {
        int k;
        cin >> k;
        jmp[0][i] = k;
    }

    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    /* for (int i = 0; i < 20; i++) { */
    /*     for (int j = 1; j <= n; j++) { */
    /*         cerr << setfill(' ') << setw(2) << jmp[i][j] << " "; */
    /*     } */
    /*     cerr << "\n"; */
    /* } */

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 20; j++)
            if (b & (1 << j))
                a = jmp[j][a];
        cout << (a ?: -1) << '\n';
    }
}
