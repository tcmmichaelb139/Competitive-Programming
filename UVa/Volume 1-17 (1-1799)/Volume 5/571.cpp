#include <bits/stdc++.h>
using namespace std;

int a, b, n;
int prev[1001];
bool done;
bool vis[1001][1001];
map<int, string> m;
vector<int> ans;

void dfs(int x, int k) {
    if (vis[x][k]) return;
    vis[x][k] = true;
    if (x == n || k == n) {
        done = true;
        return;
    }
    dfs(a, k);
    if (done) {
        ans.push_back(0);
        return;
    }
    dfs(x, b);
    if (done) {
        ans.push_back(1);
        return;
    }
    dfs(0, k);
    if (done) {
        ans.push_back(2);
        return;
    }
    dfs(x, 0);
    if (done) {
        ans.push_back(3);
        return;
    }
    dfs(x-min(x, b-k), k+min(x, b-k));
    if (done) {
        ans.push_back(4);
        return;
    }
    dfs(x+min(k, a-x), k-min(k, a-x));
    if (done) {
        ans.push_back(5);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    m[0] = "fill A", m[1] = "fill B", m[2] = "empty A", m[3] = "empty B", m[4] = "pour A B", m[5] = "pour B A";
    while (cin >> a >> b >> n) {
        ans.clear();
        memset(vis, false, sizeof(vis));
        done = false;
        dfs(0, 0);
        reverse(ans.begin(), ans.end());
        for (auto i: ans)
            cout << m[i] << '\n';
        cout << "success\n";
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

