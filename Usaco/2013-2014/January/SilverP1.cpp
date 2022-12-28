#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> time, dist;
    for (int i = 0; i < n; i++) {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'T')
            time.push(a);
        else
            dist.push(a);
    }
    dist.push(1000);

    double curd = 0, curt = 0;

    int speed = 1;

    while (!time.empty() || !dist.empty()) {
        int nt = false;
        if (dist.empty())
            nt = true;
        else if (time.size() && dist.size())
            if ((dist.top() - curd) * speed > time.top() - curt)
                nt = true;

        if (nt) {
            curd += (double)(time.top() - curt) / (double)speed;
            curt = time.top();
            time.pop();
        } else {
            curt += (dist.top() - curd) * speed;
            curd = dist.top();
            dist.pop();
        }

        speed++;
    }

    int ans = curt;
    if ((curt - ans) >= 0.5) ans++;
    cout << ans << '\n';
}
