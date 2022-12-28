#include "bits/stdc++.h"
using namespace std;

struct node {
    string s;
    bool operator<(const node& rhs) const { return s.length() < rhs.s.length(); }
};

const long long MOD = 2014;

int main() {
    freopen("scode.in", "r", stdin);
    freopen("scode.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto check = [](const string& s, const string& rem) {
        int sum = 0;
        if (s.length() > rem.length()) {
            if (s.substr(0, rem.length()) == rem)
                sum++;
            if (s.substr(s.length() - rem.length(), s.length()) == rem)
                sum++;
        }
        return sum;
    };

    string s;
    cin >> s;
    int n = s.length();
    map<string, long long> m;
    map<string, bool> vis;
    m[s] = 1;
    long long ans = 0;
    priority_queue<node> q;
    q.push({s});
    while (q.size()) {
        node cur = q.top();
        q.pop();
        if (vis[cur.s]) continue;
        vis[cur.s] = true;
        for (int i = 1; i < cur.s.length(); i++) {
            string s1 = cur.s.substr(0, cur.s.length() - i);
            string s1rem = cur.s.substr(cur.s.length() - i, cur.s.length());
            if (check(s1, s1rem)) {
                q.push({s1});
                m[s1] += m[cur.s] * check(s1, s1rem);
                m[s1] %= MOD;
            }
            string s2 = cur.s.substr(i, cur.s.length());
            string s2rem = cur.s.substr(0, i);
            if (check(s2, s2rem)) {
                q.push({s2});
                m[s2] += m[cur.s] * check(s2, s2rem);
                m[s2] %= MOD;
            }
        }
        ans += m[cur.s];
        ans %= MOD;
    }
    cout << ans - 1 << '\n';
}
