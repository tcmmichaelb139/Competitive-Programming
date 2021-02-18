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
 
int main() {
    IO("");
 
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.ln(); i++) {
        m[s[i]]++;
    }
    if (s.ln()%2 == 1) {
        char k;
        bool ok = false;
        for (auto i: m) {
            if (ok == true && i.s%2 == 1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            if (i.s%2 == 1) {
                ok = true;
                k = i.f;
            }
        }
        if (!ok) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        string ans = s;
        int x = 0;
        for (auto i: m) {
            int rx = x;
            if (k == i.f)
                continue;
            for (int j = rx; j < (i.s)/2+rx; j++) {
                ans[j] = i.f;
                ans[s.ln()-j-1] = i.f;
                x++;
            }
        }
        for (int i = x; i < m[k]/2+x; i++) {
            ans[i] = k;
            ans[s.ln()-i-1] = k;
        }
        ans[s.ln()/2] = k;
        cout << ans << '\n';
    }
    else {
        int k = 0;
        string ans = s;
        for (auto i: m) {
            if (i.s%2 == 1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            int rk = k;
            for (int j = k; j < i.s/2+rk; j++) {
                ans[j] = i.f;
                ans[s.ln()-1-j] = i.f;
                k++;
            }
        }
        cout << ans << '\n';
    }
}
