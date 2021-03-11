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
#define IMX INT_MAX
#define IMN INT_MIN

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

int main() {
    IO("");

    int n, t;
    cin >> n >> t;
    vl v;
    for (int i = 0; i < n; i++) {
        ll e;
        cin >> e;
        v.pb(e);
    }
    ll l = 0, r = 1e18;
    ll ans = 0;
    while (l <= r) {
        ll mid = l+(r-l)/2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (mid/v[i]);
            if (sum >= t) break;
        }
        if (sum >= t) {
            r = mid-1;
            ans = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans << '\n';
}
