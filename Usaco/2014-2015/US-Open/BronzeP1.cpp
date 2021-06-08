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
    IO("moocrypt");
 
    int n, m;
    cin >> n >> m;
    int ar[n][m];
    memset(ar, 0, sizeof(ar));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            ar[i][j] = s[j];
        }
    }
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    map<string, int> sol;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int a = 0; a < 8; a++) {
                if (i+2*dx[a] < 0 || j+2*dy[a] < 0 || i+2*dx[a] >= n || j+2*dy[a] >= m) continue;
                string s;
                s += ar[i][j];
                s += ar[i+dx[a]][j+dy[a]];
                s += ar[i+2*dx[a]][j+2*dy[a]];
                if (ar[i+dx[a]][j+dy[a]] == ar[i+2*dx[a]][j+2*dy[a]]) 
                    if (ar[i][j] != ar[i+dx[a]][j+dy[a]])
                        if (ar[i+dx[a]][j+dy[a]] != 'O')
                            if (ar[i][j] != 'M')
                                sol[s]++;
            }
        }
    }
    int ans = 0;
    for (auto i: sol) {
        ans = max(ans, i.s);
    }
    cout << ans << '\n';
}
