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

bool num[100000];

int main() {
    IO("highcard");

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        num[e] = true;
    }
    vi b, e;
    for (int i = 1; i <= 2*n; i++) {
        if (num[i]) e.pb(i);
        else b.pb(i);
    }
    int bi = 0, ei = 0;
    int ans = 0;
    while (bi < n && ei < n) {
        if (b[bi] > e[ei]) {
            ans++;
            bi++;
            ei++;
        }
        else {
            bi++;
        }
    }
    cout << ans << '\n';
}
