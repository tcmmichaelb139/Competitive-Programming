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
char g[1001][1001];
bool vis[1001][1001];
int area = 0;
int per = 0;

void ff(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (vis[i][j]) return;
    if (g[i][j] == '.') return;
    vis[i][j] = true;
    area++;
    ff(i+1, j);
    ff(i-1, j);
    ff(i, j+1);
    ff(i, j-1);
}

void perimeter(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (vis[i][j]) return;
    if (g[i][j] == '.') return;
    if (g[i+1][j] == '.' || i == n-1) per++;
    if (g[i-1][j] == '.' || i == 0) per++;
    if (g[i][j+1] == '.' || j == n-1) per++;
    if (g[i][j-1] == '.' || j == 0) per++;
    vis[i][j] = true;
    perimeter(i+1, j);
    perimeter(i-1, j);
    perimeter(i, j+1);
    perimeter(i, j-1);
}

int main() {
    IO("perimeter");

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j];
        }
    }
    int ans = 0;
    vpi v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            area = 0;
            ff(i, j);
            if (ans == area) {
                v.pb({i, j});
            }
            else if (ans < area) {
                v.clear();
                ans = area;
                v.pb({i, j});
            }
        }
    }
    memset(vis, false, sizeof(vis));
    int pans = IMX;
    for (int i = 0; i < v.sz(); i++) {
        per = 0;
        perimeter(v[i].f, v[i].s);
        pans = min(pans, per);
    }
    cout << ans << ' ' << pans << '\n';
}

