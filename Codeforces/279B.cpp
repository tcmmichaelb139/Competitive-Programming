//The website for this is https://codeforces.com/contest/279/problem/B
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
#define inf 1e9

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
    int v[n+2];
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        v[i] = v[i-1]+e;
    }
    int l = 0, r = 1;
    int ans = 0;
    while (l < n) {
        if (v[r]-v[l] <= t) {
            ans = max(ans, r-l);
            if (r != n)
                r++;
            else l++;
        }
        else {
            l++;
        }
    }
    cout << ans << '\n';
}
