#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> ans;

void solve(int n, int from, int to, int help) {
    if (n == 0) return;

    solve(n - 1, from, help, to);
    ans.push_back({from, to});
    solve(n - 1, help, to, from);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n, 1, 3, 2);

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';
}
