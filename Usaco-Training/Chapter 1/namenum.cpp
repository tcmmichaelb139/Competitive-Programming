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
    IO("");

    string n;
    cin >> n;
    int nlen = n.ln();
    string k;
    map<char, char> m;
    m['A'] = '2', m['B'] = '2', m['C'] = '2';
    m['D'] = '3', m['E'] = '3', m['F'] = '3';
    m['G'] = '4', m['H'] = '4', m['I'] = '4';
    m['J'] = '5', m['K'] = '5', m['L'] = '5';
    m['M'] = '6', m['N'] = '6', m['O'] = '6';
    m['P'] = '7', m['R'] = '7', m['S'] = '7';
    m['T'] = '8', m['U'] = '8', m['V'] = '8';
    m['W'] = '9', m['X'] = '9', m['Y'] = '9';
    bool tf = false;
    while (cin >> k) {
        if (k.ln() != nlen) continue;
        string numk = k;
        bool ok = true;
        for (int i = 0; i < k.ln(); i++) {
            char temp = m[k[i]];
            if (temp != n[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << k << '\n';
            tf = true;
        }
    }
    if (!tf) cout << "NONE\n";
}
