#include <bits/stdc++.h>
using namespace std;

string s, t;
int q;

bool cw[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t >> q;
    for (int i = 0; i <= 'r' - 'a'; i++) {
        for (int j = 0; j <= 'r' - 'a'; j++) {
            string s1 = "", t1 = "";
            for (int a = 0; a < s.length(); a++)
                if (s[a] - 'a' == i || s[a] - 'a' == j)
                    s1 += s[a];
            for (int a = 0; a < t.length(); a++)
                if (t[a] - 'a' == i || t[a] - 'a' == j)
                    t1 += t[a];
            if (s1 == t1)
                cw[i][j] = cw[j][i] = true;
        }
    }
    for (int i = 0; i < q; i++) {
        string x;
        cin >> x;
        bool ok = true;
        for (int a = 0; a < x.length(); a++) {
            for (int b = 0; b < x.length(); b++)
                if (!cw[x[a] - 'a'][x[b] - 'a'])
                    ok = false;
        }
        if (ok)
            cout << 'Y';
        else
            cout << 'N';
    }
    cout << '\n';
}
