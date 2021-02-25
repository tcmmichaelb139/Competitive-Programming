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

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if (l == 1) {
        if (r == n)
            cout << 0 << '\n';
        else
            cout << abs(r-pos)+1 << '\n';
    }
    else {
        if (r == n) {
            cout << abs(pos-l)+1 << '\n';
        }
        else {
            if (abs(pos-l) < abs(r-pos))
                cout << (abs(pos-l)+1)+(r-l+1) << '\n';
            else
                cout << (abs(r-pos)+1)+(r-l+1) << '\n';
        }
    }
}
