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
#define mp make_pair
 
#define ln length
 
void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
 
int main() {
    IO("");
 
    int k;
    cin >> k;
    vi v;
    ll x = 0;
    for (ll i = 1; i <= k; i++) {
        v.pb(i);
        x += i;
    }
    if (x%2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll sum1 = 0, sum2 = 0;
    ll s1 = k, s2 = k;
    bool visited[k] = {};
    vi sm1, sm2;
    while (sum1 < x/2) {
        if (s1 == 0)
            break;
        if (sum1+s1 <= x/2) {
            sum1 += s1;
            visited[s1] = true;
            sm1.pb(s1);
        }
        s1--;
    }
    while (sum2 < x/2) {
        if (s2 == 0)
            break;
        if (visited[s2]) {
            s2--;
            continue;
        }
        if (sum2+s2 <= x/2) {
            sum2 += s2;
            sm2.pb(s2);
        }
        s2--;
    }
    cout << sm1.size() << '\n';
    for (int i = 0; i < sm1.size(); i++)
        cout << sm1[i] << ' ';
    cout << '\n' << sm2.size() << '\n';
    for (int i = 0; i < sm2.size(); i++)
        cout << sm2[i] << ' ';
    cout << '\n';
}
