#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
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
 
void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
 
void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vpi k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        k.pb({i, a});
    }
    sort(all(k));
    int mxdiff = 0;
    for (int i = 0; i < n-1; i++) {
        if (abs(k[i+1].s-k[i].s) > mxdiff)
            mxdiff = abs(k[i+1].s-k[i].s);
    }
    if (mxdiff >= 2) cout << "0\n";
    else if (mxdiff == 1) cout << min(u, v) << '\n';
    else cout << min(v+u, v+v) << '\n';
}
 
int main() {
    IO("");
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
