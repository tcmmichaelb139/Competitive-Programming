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

int pre[2501][2501];

bool cmp(pi a, pi b) {
    if (a.s == b.s) return a.f < b.f;
    else return a.s < b.s;
}

int sum(int x1, int y1, int x2, int y2) {
    return pre[x2+1][y2+1]-pre[x2+1][y1]-pre[x1][y2+1]+pre[x1][y1];
}

int main() {
    IO("");

    int n;
    cin >> n;
    vpi v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(all(v));
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
        v[i].f = i+1;
    sort(all(v), cmp);
    for (int i = 0; i < n; i++)
        v[i].s = i+1;
    for (int i = 0; i < n; i++)
        pre[v[i].f][v[i].s] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] += pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x1 = min(v[i].f, v[j].f)-1;
            int x2 = max(v[i].f, v[j].f)-1;
            ans += sum(0, i, x1, j) * sum(x2, i, n-1, j);
        }
    }
    cout << ans+1 << '\n';
}
