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
vi v[3001];
vi o;
bool vis[3001];
multiset<int> no;

void dfs(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (auto i: v[k]) {
        if (no.find(i) != no.end()) continue;
        if (!vis[i]) {
            /* cout << k << ' ' << i << '\n'; */
            dfs(i);
        }
    }
}

int main() {
    IO("closing");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        o.pb(e);
    }
    bool ans[n];
    dfs(1);
    bool notok = false;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            ans[0] = false;
            notok = true;
            break;
        }
    if (!notok) 
        ans[0] = true;
    for (int i = 0; i < n-1; i++) {
        /* cout << "a;sldkjfalskdf\n"; */
        notok = false;
        no.insert(*o.begin());
        memset(vis, false, sizeof(vis));
        o.erase(o.begin());
        dfs(o[0]);
        /* for (auto i: o) */
        /*     cout << i << ' '; */
        /* cout << '\n'; */
        for (int j = 1; j <= n; j++) {
            if (no.find(j) != no.end()) continue;
            if (!vis[j]) {
                notok = true;
                ans[i+1] = false;
            }
        }
        if (!notok) 
            ans[i+1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
