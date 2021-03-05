#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define vc vector
#define pb push_back
#define pf push_front
#define rsz resize
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second

#define ln length
#define inf 1e9

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

vi v[100001];
vpi coor;
pi bl = {999999999, 99999999}, tr = {0, 0};
bool visited[100001];

void dfs(int k) {
    visited[k] = true;
    bl.f = min(coor[k-1].f, bl.f);
    bl.s = min(coor[k-1].s, bl.s);
    tr.f = max(coor[k-1].f, tr.f);
    tr.s = max(coor[k-1].s, tr.s);
    for (auto i: v[k])
        if (!visited[i]) 
            dfs(i);
}

int main() {
    IO("fenceplan");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coor.pb({x, y});
    }
    int l = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ans = 999999999;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        bl = {999999999, 999999999};
        tr = {0, 0};
        dfs(i);
        ans = min(ans, (tr.f-bl.f)*2+(tr.s-bl.s)*2);
    }
    cout << ans << '\n';
}
