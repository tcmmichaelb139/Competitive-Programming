#include <bits/stdc++.h>
using namespace std;

string s;
int q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> q;
    vector<int> C(s.length() + 1, 0);
    vector<int> O(s.length() + 1, 0);
    vector<int> W(s.length() + 1, 0);
    for (int i = 1; i <= s.length(); i++) {
        C[i] = C[i - 1];
        O[i] = O[i - 1];
        W[i] = W[i - 1];
        if (s[i - 1] == 'C')
            C[i]++;
        else if (s[i - 1] == 'O')
            O[i]++;
        else if (s[i - 1] == 'W')
            W[i]++;
        else
            assert(false);
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int c = C[b] - C[a - 1], o = O[b] - O[a - 1], w = W[b] - W[a - 1];
        /* cout << c << ' ' << o << ' ' << w << '\n'; */
        if (c == 0) {
            if (o > w)
                o--, c++, w++;
            else
                w--, c++, o++;
        } else if (c >= 2) {
            o += c - 1;
            w += c - 1;
            c = 1;
        }
        if (w > o) {
            int k = w - o;
            if (k % 2 == 0)
                w = o;
            else
                w = o + 1;
        } else {
            int k = o - w;
            if (k % 2 == 0)
                o = w;
            else
                o = w + 1;
        }
        /* cout << c << ' ' << o << ' ' << w << '\n'; */
        if (o == w && (o + w) % 4 == 0) {
            cout << 'Y';
        } else {
            cout << 'N';
        }
    }
    cout << '\n';
}
