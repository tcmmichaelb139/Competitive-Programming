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
#define sz size
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
        int k;
        cin >> k;
        ll ans = 0;
        vi v;
        for (int j = 0; j < k; j++) {
            int e;
            cin >> e;
            v.pb(e);
        }
        sort(rall(v));
        for (int j = 0; j < k; j++) {
            if (j%2 == 0) {
                if (v[j]%2 == 0)
                    ans += v[j];
            }
            else {
                if (v[j]%2 == 1)
                    ans -= v[j];
            }
        }
        if (ans == 0)
            cout << "Tie\n";
        else if (ans > 0)
            cout << "Alice\n";
        else 
            cout << "Bob\n";
    }
}
