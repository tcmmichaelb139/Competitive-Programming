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

int n;
vc<pair<pi, int>> v;
bool vis[201];
int temp;

void dfs(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        if (vis[i]) continue;
        ll dist = (v[i].f.f-v[k].f.f)*(v[i].f.f-v[k].f.f)+(v[i].f.s-v[k].f.s)*(v[i].f.s-v[k].f.s);
        if (dist < v[k].s*v[k].s) {
            /* cout << k << ' ' << i << ' ' << dist << ' ' << v[k].s*v[k].s << '\n'; */
            temp++;
            dfs(i);
        }
    }
}

int main() {
    IO("moocast");

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.pb({{a, b}, c});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(vis, false, sizeof(vis));
        temp = 0;
        dfs(i);
        ans = max(ans, temp);
    }
    cout << ans+1 << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
