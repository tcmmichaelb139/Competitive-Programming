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
    IO("hps");

    int n;
    cin >> n;
    int p[n+1], h[n+1], s[n+1];
    p[0] = 0;
    h[0] = 0;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'P') {
            p[i] = p[i-1]+1;
            h[i] = h[i-1];
            s[i] = s[i-1];
        }
        else if (c == 'H') {
            h[i] = h[i-1]+1;
            s[i] = s[i-1];
            p[i] = p[i-1];
        }
        else {
            s[i] = s[i-1]+1;
            h[i] = h[i-1];
            p[i] = p[i-1];
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int sol;
        sol = max(p[i]-p[0], max(h[i]-h[0], s[i]-s[0]));
        sol += max(p[n]-p[i], max(h[n]-h[i], s[n]-s[i]));
        ans = max(ans, sol);
    }
    cout << ans << '\n';
}
