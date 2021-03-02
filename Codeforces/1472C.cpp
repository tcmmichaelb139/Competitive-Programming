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
 
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
#define ub upper_bound
#define lb lower_bound
 
#define f first
#define s second
#define mp make_pair
 
void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
 
void solve() {
    int t;
    cin >> t;
    vi v;
    int mx = 0;
    for (int i = 0; i < t; i++) {
        int e;
        cin >> e;
        v.pb(e);
        mx = max(e, mx);
    }
    int ans = mx;
    int dp[t] = {};
    for (int i = t-1; i >= 0; i--) { //tests elements
        int k = 0;
        int k2 = i;
        while (k2 < t) {
            if (dp[k2] != 0) {
                k += dp[k2];
                break;
            }
            k += v[k2];
            k2 += v[k2];
        }
        dp[i] = k;
        ans = max(ans, k);
    }
    cout << ans << '\n';
}
 
int main() {
    IO("");
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}
