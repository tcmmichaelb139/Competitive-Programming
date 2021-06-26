#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

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
#define mp make_pair

#define ln length
#define IMX INT_MAX
#define IMN INT_MIN

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

int n, m;
vi v[100001];
vi rv[100001];
bool vis[100001];
bool rvis[100001];

void dfs(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (auto i: v[k])
        if (!vis[i]) 
            dfs(i);
}

void dfs2(int k) {
    if (rvis[k]) return;
    rvis[k] = true;
    for (auto i: rv[k]) {
        if (!rvis[i]) 
            dfs2(i);
    }
}

int main() {
    IO("");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        rv[b].pb(a);
    }

    dfs(1);
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << 1 << ' ' << i << '\n';
            return 0;
        }
        if (!rvis[i]) {
            cout << "NO\n" << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES\n";
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
