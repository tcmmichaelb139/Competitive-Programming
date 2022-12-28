#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int cur = 0;
    vector<int> v;
    while (getline(cin, s)) {
        if (s == "") {
            v.push_back(cur);
            cur = 0;
        } else
            cur += stoi(s);
    }
    sort(rbegin(v), rend(v));
    cout << v[0] + v[1] + v[2] << '\n';
}
