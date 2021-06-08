#######
####### DISCLAIMER: THIS GET 10/10 ON ALPHASTAR BUT GETS 9/10 ON USACO, TEST CASE 10 GETS TLE
#######
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

int main() {
    IO("diamond");

    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int ar1[n], ar2[n];
    ar1[n] = 0;
    ar2[n] = 0;
    int l = 0, r = 1;
    for (; l < n; l++) {
        r = l;
        while (r < n && v[r]-v[l] <= k) r++;
        ar1[l] = r-l;
    }
    l = n-1;
    for (; l >= 0; l--) {
        r = l;
        while (r >= 0 && v[l]-v[r] <= k) r--;
        ar2[l] = l-r;
    }
    for (int i = n-2; i >= 0; i--)
        ar1[i] = max(ar1[i+1], ar1[i]);
    for (int i = 1; i < n; i++)
        ar2[i] = max(ar2[i-1], ar2[i]);

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, ar2[i-1]+ar1[i]);
    cout << ans << '\n';
}

