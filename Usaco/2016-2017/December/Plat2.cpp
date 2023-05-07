#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000009;
int add(int a, int b) { return ((a + b) % MOD + MOD) % MOD; }

int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> fj(N), fp(M);
    for (int i = 0; i < N; i++)
        cin >> fj[i];
    for (int i = 0; i < M; i++)
        cin >> fp[i];

    int dp[N + 1][M + 1][K + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (dp[i][j][k] == 0) continue;
                if (i < N)
                    dp[i + 1][j][k] = add(dp[i + 1][j][k], dp[i][j][k]);
                if (j < M)
                    dp[i][j + 1][k] = add(dp[i][j + 1][k], dp[i][j][k]);
                if (i < N && j < M)
                    dp[i + 1][j + 1][k] = add(dp[i + 1][j + 1][k], -dp[i][j][k]);

                if (i < N && j < M && k < K) {
                    if (fj[i] > fp[j]) {
                        dp[i + 1][j + 1][k + 1] = add(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                    }
                }
            }
        }
    }

    cout << dp[N][M][K] << '\n';
}
