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
bool vis[100001];

void dfs(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (auto i: v[k]) 
        if (!vis[i])
            dfs(i);
}

int main() {
    IO("");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ans = 0;
    int prev = 1;
    vpi ar;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            prev = i;
            continue;
        }
        dfs(i);
        ans++;
        if (i == 1) continue;
        ar.pb({prev, i});
        prev = i;
    }
    cout << ans-1 << '\n';
    for (auto i: ar)
        cout << i.f << ' ' << i.s << '\n';
}
