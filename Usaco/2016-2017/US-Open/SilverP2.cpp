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
    IO("cownomics");

    int n, m;
    cin >> n >> m;
    vs unspot(n), spot(n);
    for (int i = 0; i < n; i++) {
        cin >> unspot[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> spot[i];
    }
    int ans = 0;
    for (int i = 0; i < m-2; i++) {
        for (int j = i+1; j < m-1; j++) {
            for (int a = j+1; a < m; a++) {
                set<string> s;
                for (int b = 0; b < n; b++) {
                    string temps;
                    temps += unspot[b][i];
                    temps += unspot[b][j];
                    temps += unspot[b][a];
                    s.insert(temps);
                }
                bool ok = true;
                for (int b = 0; b < n; b++) {
                    string temps;
                    temps += spot[b][i];
                    temps += spot[b][j];
                    temps += spot[b][a];
                    if (s.find(temps) != s.end()) {
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    continue;
                else {
                   ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}

