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

    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e%2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    int ans = 0;
    bool eo = true;
    bool ok = false;
    while (true) {
        if (even == 0 && odd == 0) {
            break;
        }
        if (eo) {
            if (even > 0) {
                even--;
            }
            else if (odd > 1) {
                odd -= 2;
            }
            else {
                ok = true;
                break;
            }
            ans++;
            eo = false;
        }
        else {
            if (odd > 0) {
                odd--;
            }
            else {
                break;
            }
            eo = true;
            ans++;
        }
    }
    if (ok)
        ans--;
    cout << ans << '\n';
}
