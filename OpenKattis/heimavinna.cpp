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

    string s;
    cin >> s;
    int ans = 0;
    string k = "";
    string s1 = "";
    string s2 = "";
    bool ok = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ';' && s[i] != '-') {
            k += s[i];
        }
        else {
            if (s[i] == ';') {
                s2 = k;
                if (ok) {
                    ans += stoi(s2)-stoi(s1)+1;
                    ok = false;
                    k = "";
                }
                else {
                    ans++;
                    k = "";
                }
            }
            else {
                s1 = k;
                ok = true;
                k = "";
            }
        }
        if (i == s.length()-1) {
            s2 = k;
            if (ok) {
                ans += stoi(s2)-stoi(s1)+1;
                ok = false;
                k = "";
            }
            else {
                ans++;
                k = "";
            }
        }

    }
    cout << ans << '\n';
}
