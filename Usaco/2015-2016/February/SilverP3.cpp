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

int x, y, k, m;
bool vis[101][101][201];
int ans = IMX;

void ff(int a, int b, int t) {
    if (vis[a][b][t]) return;
    /* cout << a << ' ' << b << ' ' << a+b << ' ' << t << '\n'; */
    if (t > k) return;
    vis[a][b][t] = true;
    ans = min(ans, abs(a+b-m));
    t++;
    ff(0, b, t);
    ff(x, b, t);
    ff(a, 0, t);
    ff(a, y, t);
    if (x-a > b) 
        ff(a+b, 0, t);
    else 
        ff(x, b-(x-a), t);
    if (a < y-b)
        ff(0, a+b, t);
    else 
        ff(a-(y-b), y, t);
}

int main() {
    IO("pails");

    cin >> x >> y >> k >> m;
    ff(0, 0, 0);
    cout << ans << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
