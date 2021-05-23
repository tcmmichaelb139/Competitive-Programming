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
string s;
bool ar[4004][4004];
bool vis[4004][4004];
int sx = IMX, sy = IMX, lx = -1, ly = -1;

void ff(int i, int j) {
    if (i < sx-1 || i > lx+1 || j < sy-1 || j > ly+1) return;
    if (vis[i][j]) return;
    if (ar[i][j]) return;
    vis[i][j] = true;
    ff(i+1, j);
    ff(i-1, j);
    ff(i, j+1);
    ff(i, j-1);
}

int main() {
    IO("gates");

    cin >> n >> s;
    int x = 2002, y = 2002;
    ar[x][y] = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N')
            x++;
        else if (s[i] == 'E')
            y++;
        else if (s[i] == 'S')
            x--;
        else 
            y--;
        ar[x][y] = true;
        if (s[i] == 'N')
            x++;
        else if (s[i] == 'E')
            y++;
        else if (s[i] == 'S')
            x--;
        else 
            y--;
        ar[x][y] = true;
        sx = min(sx, x);
        lx = max(lx, x);
        sy = min(sy, y);
        ly = max(ly, y);
    }
    /* for (int i = sx-1; i < lx+2; i++) { */
    /*     for (int j = sy-1; j < ly+2; j++) { */
    /*         if (ar[i][j]) cout << 1; */
    /*         else cout << 0; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
    /* cout << sx << ' ' << lx << ' ' << sy << ' ' << ly << '\n'; */
    int ans = 0;
    for (int i = sx-1; i < lx+2; i++) {
        for (int j = sy-1; j < ly+2; j++) {
            if (vis[i][j]) continue;
            if (ar[i][j]) continue;
            /* cout << i << ' ' << j << '\n'; */
            ff(i, j);
            ans++;
        }
    }
    cout << ans-1 << '\n';
}
