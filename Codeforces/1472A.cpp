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
#define rsz resize
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
 
int main() {
    IO("");
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int w, h, n;
        cin >> w >> h >> n;
        int ans = 1;
        while (h%2 == 0) {
            h /= 2;
            ans*=2;
        }
        while (w%2 == 0) {
            w /= 2;
            ans*=2;
        }
        if (ans >= n)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}
