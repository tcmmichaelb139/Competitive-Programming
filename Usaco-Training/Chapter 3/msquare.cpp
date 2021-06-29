#include <bits/stdc++.h>
using namespace std;

// template {{{
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
//}}}

int main() {
    IO("");

    string ans = "12345678";
    for (int i = 0; i < 8; i++) {
        char k;
        cin >> k;
        k--;
        ans[i] = k;
    }
    unordered_set<string> vis;
    map<str, str> m;
    vi A = {7, 6, 5, 4, 3, 2, 1, 0}, B = {3, 0, 1, 2, 5, 6, 7, 4}, C = {0, 6, 1, 3, 4, 2, 5, 7};
    queue<string> q;
    q.push("01234567");
    m["01234567"] = "";
    while (!q.empty()) {
        string v = "12345678";
        bool found = true;
        for (int i = 0; i < 8; i++) {
            v[i] = q.front()[i];
            if (v[i] != ans[i]) found = false;
        }
        q.pop();
        /* cout << v << '\n'; */
        if (found) break;
        string tmp1 = "12345678", tmp2 = "12345678", tmp3 = "12345678";
        for (int i = 0; i < 8; i++) {
            tmp1[i] = v[A[i]];
            tmp2[i] = v[B[i]];
            tmp3[i] = v[C[i]];
        }
        if (vis.find(tmp1) == vis.end()) {
            q.push(tmp1);
            m[tmp1] = m[v]+'A';
            vis.insert(tmp1);
        }
        if (vis.find(tmp2) == vis.end()) {
            q.push(tmp2);
            m[tmp2] = m[v]+'B';
            vis.insert(tmp2);
        }
        if (vis.find(tmp3) == vis.end()) {
            q.push(tmp3);
            m[tmp3] = m[v]+'C';
            vis.insert(tmp3);
        }
    }
    cout << m[ans].ln() << '\n';
    cout << m[ans] << '\n';
}
