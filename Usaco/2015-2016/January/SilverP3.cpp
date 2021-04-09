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

bool ar[4002][4002];
bool vis[4002][4002];
int sx = 4000, sy = 4000, lx = 0, ly = 0;

void ff(int x, int y) {
    if (x < sx || y < sy || x > lx || y > ly) return;
    if (vis[x][y]) return;
    if (ar[x][y]) return;
    vis[x][y] = true;
    ff(x+1, y);
    ff(x-1, y);
    ff(x, y+1);
    ff(x, y-1);
}

int main() {
    IO("gates");

    int n;
    cin >> n;
    string s;
    cin >> s;
    int currx = 1001, curry = 1001;
    ar[currx][curry] = true;
    for (int i = 0; i < n; i++) {
        int x = 0, y = 0;
        if (s[i] == 'N') y = 1;
        if (s[i] == 'E') x = 1;
        if (s[i] == 'S') y = -1;
        if (s[i] == 'W') x = -1;
        for (int i = 0; i < 2; i++) {
            currx += x;
            curry += y;
            ar[currx][curry] = true;
        }
        sx = min(sx, currx);
        lx = max(lx, currx);
        sy = min(sy, curry);
        ly = max(ly, curry);
    }
    int ans = 0;
    sx--;
    sy--;
    lx++;
    ly++;
    for (int i = sx; i <= lx; i++) {
        for (int j = sy; j <= ly; j++) {
            if (vis[i][j] || ar[i][j]) continue;
            ff(i, j);
            ans++;
        }
    }
    cout << max(0, ans-1) << '\n';
}
