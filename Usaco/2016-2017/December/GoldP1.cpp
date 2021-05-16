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
vpi v;
vpi v2;
/* bool vis[25001][25001]; */
bool vis[1000];

void dfs(int x, int dist) {
    if (vis[x]) return;
    vis[x] = true;
    for (int i = 0; i < v.sz(); i++) {
        int k = (v[i].f-v[x].f)*(v[i].f-v[x].f)+(v[i].s-v[x].s)*(v[i].s-v[x].s);
        if (!vis[i] && k <= dist) 
            dfs(i, dist);
    }
}

int main() {
    IO("moocast");

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v2.pb({a, b});
    }
    ll l = 0, r = IMX;
    while (l <= r) {
        v.clear();
        v = v2;
        memset(vis, false, sizeof(vis));
        ll mid = l+(r-l)/2LL;
        dfs(0, mid);
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                ok = false;
        /* cout << l << ' ' << r << '\n'; */
        if (ok) r = mid-1;
        else l = mid+1;
    }
    cout << l << '\n';
}
