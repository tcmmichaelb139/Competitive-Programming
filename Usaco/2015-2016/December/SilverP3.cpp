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
    IO("bcount");

    int n, q;
    cin >> n >> q;
    int h[n+1] = {};
    int g[n+1] = {};
    int j[n+1] = {};
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (i == 0) {
            if (k == 1)
                h[i+1] = 1;
            else if (k == 2)
                g[i+1] = 1;
            else 
                j[i+1] = 1;
        }
        else {
            if (k == 1) {
                h[i+1] = 1+h[i];
                g[i+1] = g[i];
                j[i+1] = j[i];
            }
            else if (k == 2) {
                g[i+1] = 1+g[i];
                h[i+1] = h[i];
                j[i+1] = j[i];
            }
            else {
                j[i+1] = 1+j[i];
                g[i+1] = g[i];
                h[i+1] = h[i];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << h[b]-h[a-1] << ' ';
        cout << g[b]-g[a-1] << ' ';
        cout << j[b]-j[a-1] << '\n';
    }
}
