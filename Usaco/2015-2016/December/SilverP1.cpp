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

vpi v[101][101];
bool vis[101][101];
bool lon[101][101];
int n, m;
int ans = 0;

void ff(int x, int y) {
    if (x <= 0 || y <= 0 || y > n || x > n) return;
    if (vis[x][y]) return;
    vis[x][y] = true;
    for (auto i: v[x][y]) {
        lon[i.f][i.s] = true;
    }
    if (lon[x+1][y]) ff(x+1, y);
    if (lon[x-1][y]) ff(x-1, y);
    if (lon[x][y+1]) ff(x, y+1);
    if (lon[x][y-1]) ff(x, y-1);
}

int main() {
    IO("lightson");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].pb({a, b});
    }
    bool curr[101][101];
    lon[1][1] = true;
    while (true) {
        ff(1, 1);
        memset(vis, false, sizeof(vis));
        bool ok = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (curr[i][j] != lon[i][j]) ok = false;
            }
        if (ok) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                curr[i][j] = lon[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (lon[i][j]) ans++;
            //if (lon[i][j]) cout << "1 ";
            //else cout << "0 ";
        }
        //cout << '\n';
    }
    cout << ans << '\n';
}
